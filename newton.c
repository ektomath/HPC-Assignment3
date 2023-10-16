#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	/*************************** READ CLI HERE **************************/
    int nrThreads;
	int lines;
    int degreePolynomial;

	printf(" #arguments: %d\n", argc);
	for (int i = 1; i < argc; i++) { // iterate through the received character vector
		if (strncmp(argv[i], "-t", 2) == 0) { // checks if the  -t prefix is found
            nrThreads = atoi(argv[i] + 2);
		} else if (strncmp(argv[i], "-l", 2) == 0) { // checks if the -l prefix is found
			lines = atoi(argv[i] + 2);
		}
        degreePolynomial = atoi(argv[argc-1]); // last character will be the polynomial degree
	}
	printf(" nrThreads is %d\n nrLines is %d\n degreePolynomial is %d\n", nrThreads, lines, degreePolynomial);

    /********* READ FILE CONTAINING PRECOMPUTED ROOTS ***************/
    FILE *file = fopen("roots.txt", "r");
    if (file == NULL) {
        perror("Error opening file to read");
        return 1;
    }
    int startRows[] = {0, 2, 5, 9, 14, 20, 27, 35, 44};
    fseek(file,  startRows[degreePolynomial - 1] * ( 7 * 2 + 3) , SEEK_SET); // sets file pointer to correct start position
    float **matrixRoots = (float **)malloc(degreePolynomial * sizeof(float *));
    for (int i = 0; i < degreePolynomial; i++) {
        matrixRoots[i] = (float *)malloc(2 * sizeof(float));
    }
    float realPart, imaginaryPart;
    for (int rootNr = 0; rootNr < degreePolynomial; rootNr++) {
        fscanf(file, "%f %f", &realPart, &imaginaryPart);
        matrixRoots[rootNr][0] = realPart;
        matrixRoots[rootNr][1] = imaginaryPart;
    }


    // Iterate through the matrix and print each element, for testing
    for (int i = 0; i < degreePolynomial; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f\t", matrixRoots[i][j]);
        }
        printf("\n"); // Move to the next row
    }
    /*************************** COMPUTE NEWTONS METHOD HERE **************************/

    /*************************** WRITE IMAGE HERE **************************/
}
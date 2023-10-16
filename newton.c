#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	/*************************** READ CLI HERE **************************/
    int nrThreads;
	int lines;
    int degreePolynomial;
    int nrBaseColors = 3; // RGB

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
    int startPosition[] = {0, 17, 50, 99, 164, 244, 340, 453, 582};
    fseek(file,  startPosition[degreePolynomial - 1], SEEK_SET); // sets file pointer to correct start position
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
    fclose(file);
    /*
    for (int i = 0; i < degreePolynomial; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrixRoots[i][j]);
        }
    }*/
    /*************************** COMPUTE NEWTONS METHOD HERE **************************/

    /*************************** WRITE IMAGE HERE **************************/
    unsigned char **colorsMatrix = (unsigned char **) malloc(lines * lines * sizeof(unsigned char *));
    for (int i = 0; i < lines * lines; i++) {
        colorsMatrix[i] = (unsigned char *) malloc(nrBaseColors * sizeof(unsigned char));
    }
    for (int i = 0; i < lines * lines; i++) {
        colorsMatrix[i][0] = 0;
        colorsMatrix[i][1] = 255;
        colorsMatrix[i][2] = 0;
    }

    for (int i = 0; i < lines * lines; i++) {
        for (int j = 0; j < nrBaseColors; j++) {
            printf("%d ", colorsMatrix[i][j]);
        }
        printf("(row %d) \n", i);
    }

    // Open a file for writing
    FILE *outFile = fopen("newton_attractors_xd.ppm", "wb"); // "wb" for binary write mode

    if (outFile == NULL) {
        perror("Error opening the file");
        return 1;
    }
    fprintf(outFile, "P3\n%d %d\n%d\n", lines, lines, 255);


    // Close the file
    fclose(outFile);

    // free memory stuff here
    for (int i = 0; i < degreePolynomial; i++) {
        free(matrixRoots[i]);
    }
    free(matrixRoots);

    for (int i = 0; i < lines * lines; i++) {
        free(colorsMatrix[i]);
    }
    free(colorsMatrix);
    return 0;
}
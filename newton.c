#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>


char colorsPalette[10][12] = {"251 180 174\n", "179 205 227\n", "204 235 197\n", "222 203 228\n", "254 217 166\n", "255 255 204\n", "229 216 189\n", "253 218 236\n", "242 242 242\n", "255 255 255\n"};


typedef struct {
    float realPart;
    float imaginaryPart;
    unsigned char indexOfRoot;
} TYPE_ATTR ;

typedef struct {
    float realPart;
    float imaginaryPart;
    unsigned char iterationsToConverge;
} TYPE_CONV;

int checkTermination(int degree, float complex* rootsArray, float complex x) {
    float tolerance = 0.000001; // 10^-6
    long int xMax = 10000000000;
    for (int root = 0; root < degree; root++) { // checks if distance from x to all the other roots is small enough
        float distance = (creal(x) - creal(rootsArray[root])) * (creal(x) - creal(rootsArray[root])) + (cimag(x) - cimag(rootsArray[root])) * (cimag(x) - cimag(rootsArray[root]));
        if (distance < tolerance) {
            return root;
        }
    }
    if ( creal(x) * creal(x) + cimag(x)* cimag(x)  < tolerance) { // check if distance from x to 0 is small
        return 10;
    } if (creal(x) > xMax || -creal(x) > xMax) { // checks if real part of x is too large
        printf("too muchhhh");
        return 10;
    } if (cimag(x) > xMax || -cimag(x) > xMax) {
        printf("too muchhhh");
        return 10;
    }
    return 99;
}


void newtonsMethod(int degree, complex float* rootsArray, TYPE_ATTR* startNumber) {
    short maxIterations = 128;
    float complex x = startNumber->realPart + startNumber->imaginaryPart * I;
    //printf("complex real part: %f, complex img part: %f \n", creal(x), cimag(x));
    switch ( degree ) {
        case 1:
            startNumber->indexOfRoot = 0;
            goto exit_switch;
        case 2:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = x/2 + 1/(2*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 3:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 2*x/3 + 1 / (3*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 4:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 3*x/4 + 1 / (4*x*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 5:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 4*x/5 + 1 / (5*x*x*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 6:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 5*x/6 + 1 / (6*x*x*x*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 7:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 6*x/7 + 1 / (7*x*x*x*x*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 8:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 7*x/8 + 1 / (8*x*x*x*x*x*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;
        case 9:
            for (int iteration = 0; iteration < maxIterations; iteration ++) {
                //printf("iteration: %d\n", iteration);
                x = 8*x/9 + 1 / (9*x*x*x*x*x*x*x*x);
                startNumber->indexOfRoot = checkTermination(degree, rootsArray, x);
                //printf(" rootIndex %d\n", startNumber->indexOfRoot);
                if (startNumber->indexOfRoot != 99) {
                    goto exit_switch;
                }
            }
            break;

        default:
            fprintf(stderr, "Erorrporo: unexpected degree\n");
            exit(1);
    }
    startNumber->indexOfRoot = 10;
    exit_switch:
}


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
    int startPosition[] = {0, 17, 50, 99, 164, 244, 340, 453, 582};
    fseek(file,  startPosition[degreePolynomial - 1], SEEK_SET); // sets file pointer to correct start position

    float realPart, imaginaryPart;
    float complex rootsArray[degreePolynomial];
    float complex root;
    for (int rootNr = 0; rootNr < degreePolynomial; rootNr++) {
        fscanf(file, "%f %f", &realPart, &imaginaryPart);
        root = realPart + imaginaryPart * I;
        rootsArray[rootNr] = root;
    }

    fclose(file);

    /*************************** COMPUTE NEWTONS METHOD HERE **************************/
    //TYPE_ATTR firstX0;
    //firstX0.realPart = -1/2;
    //firstX0.imaginaryPart = -1;
    //newtonsMethod(degreePolynomial, rootsArray, &firstX0);
    //printf("converges towards root nr %d\n", firstX0.indexOfRoot);

    // iterate through all pixels = lines*lines
    // save found root for each pixel
    // give each root a color
    // write color to file

    float spacing = (-2.0 - 2.0) / (lines - 1.0);

    TYPE_ATTR pixels[lines][lines];
    for (int iReal = 0; iReal < lines; iReal++) {
        for (int iImag = 0; iImag < lines; iImag++) {
            pixels[iImag][iReal].realPart = -2 - iReal * spacing;
            pixels[iImag][iReal].imaginaryPart = -2 - iImag * spacing;
            newtonsMethod(degreePolynomial, rootsArray, &pixels[iImag][iReal]);
            //printf("real part: %f, imaginary part: %f, root found %d.\n", pixels[iImag][iReal].realPart, pixels[iImag][iReal].imaginaryPart, pixels[iImag][iReal].indexOfRoot);
        }
    }



    /*************************** WRITE IMAGE HERE **************************/



    // Open a file for writing
    FILE *outFile = fopen("newton_attractors_xd.txt", "wb"); // "wb" for binary write mode
    if (outFile == NULL) {
        perror("Error opening the file");
        return 1;
    }
    fprintf(outFile, "P3\n%d %d\n%d\n", lines, lines, 255);
    for (int iReal = 0; iReal < lines; iReal++) {
        for (int iImag = 0; iImag < lines; iImag++) {
            fwrite(colorsPalette[pixels[iImag][iReal].indexOfRoot], sizeof(char), 12, outFile);
        }
    }



    /*char red[] = "255 0 0\n";
    char green[] = "0 255 0\n";
    char blue[] = "0 0 255\n";
    char str[7];

    for ( int line = 0; line < lines * lines; line++ ) {
        fwrite(green, sizeof(char), 8, outFile);
    }*/
    // Close the file
    fclose(outFile);

    return 0;
}
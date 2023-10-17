#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>


char colorsPalette[10][12] = {"251 180 174\n", "179 205 227\n", "204 235 197\n", "222 203 228\n", "254 217 166\n", "255 255 204\n", "229 216 189\n", "253 218 236\n", "242 242 242\n", "255 255 255\n"};
//char colorsPaletteGrayscale[9][12] = {"000 000 000\n", "037 037 037\n", "082 082 082\n", "115 115 115\n", "150 150 150\n", "189 189 189\n", "217 217 217\n", "240 240 240\n", "255 255 255\n"};
char colorsPaletteGrayscale[130][12] = {
        "start0000000",
        "000 000 000\n",
        "002 002 002\n",
        "004 004 004\n",
        "006 006 006\n",
        "008 008 008\n",
        "010 010 010\n",
        "012 012 012\n",
        "014 014 014\n",
        "016 016 016\n",
        "018 018 018\n",
        "020 020 020\n",
        "022 022 022\n",
        "024 024 024\n",
        "026 026 026\n",
        "028 028 028\n",
        "030 030 030\n",
        "032 032 032\n",
        "034 034 034\n",
        "036 036 036\n",
        "038 038 038\n",
        "040 040 040\n",
        "042 042 042\n",
        "044 044 044\n",
        "046 046 046\n",
        "048 048 048\n",
        "050 050 050\n",
        "052 052 052\n",
        "054 054 054\n",
        "056 056 056\n",
        "058 058 058\n",
        "060 060 060\n",
        "062 062 062\n",
        "064 064 064\n",
        "066 066 066\n",
        "068 068 068\n",
        "070 070 070\n",
        "072 072 072\n",
        "074 074 074\n",
        "076 076 076\n",
        "078 078 078\n",
        "080 080 080\n",
        "082 082 082\n",
        "084 084 084\n",
        "086 086 086\n",
        "088 088 088\n",
        "090 090 090\n",
        "092 092 092\n",
        "094 094 094\n",
        "096 096 096\n",
        "098 098 098\n",
        "100 100 100\n",
        "102 102 102\n",
        "104 104 104\n",
        "106 106 106\n",
        "108 108 108\n",
        "110 110 110\n",
        "112 112 112\n",
        "114 114 114\n",
        "116 116 116\n",
        "118 118 118\n",
        "120 120 120\n",
        "122 122 122\n",
        "124 124 124\n",
        "126 126 126\n",
        "128 128 128\n",
        "130 130 130\n",
        "132 132 132\n",
        "134 134 134\n",
        "136 136 136\n",
        "138 138 138\n",
        "140 140 140\n",
        "142 142 142\n",
        "144 144 144\n",
        "146 146 146\n",
        "148 148 148\n",
        "150 150 150\n",
        "152 152 152\n",
        "154 154 154\n",
        "156 156 156\n",
        "158 158 158\n",
        "160 160 160\n",
        "162 162 162\n",
        "164 164 164\n",
        "166 166 166\n",
        "168 168 168\n",
        "170 170 170\n",
        "172 172 172\n",
        "174 174 174\n",
        "176 176 176\n",
        "178 178 178\n",
        "180 180 180\n",
        "182 182 182\n",
        "184 184 184\n",
        "186 186 186\n",
        "188 188 188\n",
        "190 190 190\n",
        "192 192 192\n",
        "194 194 194\n",
        "196 196 196\n",
        "198 198 198\n",
        "200 200 200\n",
        "202 202 202\n",
        "204 204 204\n",
        "206 206 206\n",
        "208 208 208\n",
        "210 210 210\n",
        "212 212 212\n",
        "214 214 214\n",
        "216 216 216\n",
        "218 218 218\n",
        "220 220 220\n",
        "222 222 222\n",
        "224 224 224\n",
        "226 226 226\n",
        "228 228 228\n",
        "230 230 230\n",
        "232 232 232\n",
        "234 234 234\n",
        "236 236 236\n",
        "238 238 238\n",
        "240 240 240\n",
        "242 242 242\n",
        "244 244 244\n",
        "246 246 246\n",
        "248 248 248\n",
        "250 250 250\n",
        "252 252 252\n",
        "254 254 254\n",
        "end00000000\n"
};

float complex rootsPol1[] = {1.0000 + 0.0000 * I};
float complex rootsPol2[] = {1.0000 + 0.0000 * I, -1.0000 + 0.0000 * I};
float complex rootsPol3[] = {1.0000 + 0.0000 * I, -0.5000 + 0.8660 * I, -0.5000 - 0.8660 * I};
float complex rootsPol4[] = {1.0000 + 0.0000 * I, -1.0000 + 0.0000 * I, 0.0000 + 1.0000 * I,
                             0.0000 - 1.0000 * I};
float complex rootsPol5[] = {1.0000 + 0.0000 * I, -0.8090 + 0.5878 * I, -0.8090 - 0.5878 * I,
                             0.3090 + 0.9511 * I, 0.3090 - 0.9511 * I};
float complex rootsPol6[] = {1.0000 + 0.0000 * I, -1.0000 + 0.0000 * I, -0.5000 + 0.8660 * I,
                             -0.5000 - 0.8660 * I, 0.5000 + 0.8660 * I, +0.5000 - 0.8660 * I};
float complex rootsPol7[] = {1.0000 + 0.0000 * I, -0.9010 + 0.4339 * I, -0.9010 - 0.4339 * I,
                             -0.2225 + 0.9749 * I, -0.2225 - 0.9749 * I, 0.6235 + 0.7818 * I,
                             0.6235 - 0.7818 * I};
float complex rootsPol8[] = {1.0000 + 0.0000 * I, -1.0000 + 0.0000 * I, 0.0000 + 1.0000 * I,
                             0.0000 - 1.0000 * I, -0.7071 + 0.7071 * I, -0.7071 - 0.7071 * I,
                             0.7071 + 0.7071 * I, 0.7071 - 0.7071 * I};
float complex rootsPol9[] = {1.0000 + 0.0000 * I, -0.9397 + 0.3420 * I, -0.9397 - 0.3420 * I,
                             -0.5000 + 0.8660 * I, -0.5000 - 0.8660 * I, 0.1736 + 0.9848 * I,
                             0.1736 - 0.9848 * I, 0.7660 + 0.6428 * I, 0.7660 - 0.6428 * I};

typedef struct {
    float realPart;
    float imaginaryPart;
    unsigned char indexOfRoot;
    short iterationsToConverge;
} TYPE_ATTR ;

//typedef struct {
//    float realPart;
//    float imaginaryPart;
//    unsigned char iterationsToConverge;
//} TYPE_CONV;

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
        return 9;
    } if (creal(x) > xMax || -creal(x) > xMax) { // checks if real part of x is too large
        //printf("too muchhhh\n");
        return 9;
    } if (cimag(x) > xMax || -cimag(x) > xMax) { // checks if imaginary part of x is too large
        //printf("too muchhhh\n");
        return 9;
    }
    return 99;
}


void newtonsMethod(int degree, complex float* rootsArray, TYPE_ATTR* startNumber) {
    int iteration = 1;
    short maxIterations = 128;
    float complex x = startNumber->realPart + startNumber->imaginaryPart * I;
    //printf("complex real part: %f, complex img part: %f \n", creal(x), cimag(x));
    switch ( degree ) {
        case 1:
            startNumber->indexOfRoot = 0;
            goto exit_switch;
        case 2:
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
            for (; iteration < maxIterations; iteration ++) {
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
    startNumber->indexOfRoot = 9;
    exit_switch:
    startNumber->iterationsToConverge = iteration;
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

    /********* GET PRECOMPUTED ROOTS ***************/
    float complex rootsArray[degreePolynomial];
    switch (degreePolynomial) {
        case 1:
             memcpy((void*)rootsArray, rootsPol1, sizeof(rootsArray));
             break;
        case 2:
            memcpy((void*)rootsArray, rootsPol2, sizeof(rootsArray));
            break;
        case 3:
            memcpy((void*)rootsArray, rootsPol3, sizeof(rootsArray));
            break;
        case 4:
            memcpy((void*)rootsArray, rootsPol4, sizeof(rootsArray));
            break;
        case 5:
            memcpy((void*)rootsArray, rootsPol5, sizeof(rootsArray));
            break;
        case 6:
            memcpy((void*)rootsArray, rootsPol6, sizeof(rootsArray));
            break;
        case 7:
            memcpy((void*)rootsArray, rootsPol7, sizeof(rootsArray));
            break;
        case 8:
            memcpy((void*)rootsArray, rootsPol8, sizeof(rootsArray));
            break;
        case 9:
            memcpy((void*)rootsArray, rootsPol9, sizeof(rootsArray));
            break;
        default:
            printf("Error: something went wrong with the polynom degree...\n");
            return -1;
    }

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

    TYPE_ATTR *pixelsEntries = (TYPE_ATTR*) malloc(sizeof(TYPE_ATTR) * lines * lines);
    TYPE_ATTR **pixels = (TYPE_ATTR**) malloc(sizeof(TYPE_ATTR*) * lines);
    for ( size_t i = 0, j = 0; i < lines; ++i, j+=lines )
        pixels[i] = pixelsEntries + j;

    for (int iImag = 0; iImag < lines; iImag++) {
        for (int iReal = 0; iReal < lines; iReal++) {
            pixels[iImag][iReal].realPart = -2 - iReal * spacing;
            pixels[iImag][iReal].imaginaryPart = -2 - iImag * spacing;
            newtonsMethod(degreePolynomial, rootsArray, &pixels[iImag][iReal]);
            //printf("real part: %f, imaginary part: %f, root found %d.\n", pixels[iImag][iReal].realPart, pixels[iImag][iReal].imaginaryPart, pixels[iImag][iReal].indexOfRoot);
        }
    }



    /*************************** WRITE IMAGE HERE **************************/
    // Open a file for writing
    FILE *colorFile = fopen("newton_attractors_xd.txt", "wb"); // "wb" for binary write mode
    if (colorFile == NULL) {
        perror("Error opening the file");
        return 1;
    }
    FILE *grayFile = fopen("newton_convergence_xd.txt", "wb"); // "wb" for binary write mode
    if (grayFile == NULL) {
        perror("Error opening the file");
        return 1;
    }
    fprintf(grayFile, "P3\n%d %d\n%d\n", lines, lines, 255);
    fprintf(colorFile, "P3\n%d %d\n%d\n", lines, lines, 255);
    int counter = 0;
    for (int iReal = 0; iReal < lines; iReal++) {
        for (int iImag = 0; iImag < lines; iImag++, counter++) {
            fwrite(colorsPalette[pixels[iImag][iReal].indexOfRoot], sizeof(char), 12, colorFile);
            fwrite(colorsPaletteGrayscale[pixels[iImag][iReal].iterationsToConverge], sizeof(char), 12, grayFile);
        }
    }
    fclose(colorFile);

    free(pixelsEntries);
    free(pixels);
    return 0;
}

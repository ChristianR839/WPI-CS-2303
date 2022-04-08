#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main(int argc, char* argv[]) {

    // Don't worry about handling incorrect input
    // %f print as floating point number
    // %d print as decimal number
    // ^ look up "c language format specifiers" to see full list

    float x = atof(argv[1]);
    int howManyAs = argc - 2;

    float sum = 0;

    for (int i = 0; i < howManyAs; i++) {
        float thisA = atof(argv[i+2]);
        sum += thisA * raiseIt(x, i);
    }

    printf("argc is %d\n", argc - 1);
    printf("sum is %f\n", sum);
}

float raiseIt(float base, int exponent) {
    float answer = 1;
    for (int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

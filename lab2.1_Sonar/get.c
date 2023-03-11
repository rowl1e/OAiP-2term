#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_ () {
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

int getintMin (int min) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || getchar() != '\n') {
            error_();
            rewind(stdin);
    }
    return integer;
}

int getintMinMax (int min, int max) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || integer > max || getchar() != '\n') {
            error_();
            rewind(stdin);
    }
    return integer;
}

float getfloatMin (int min) {
    float x;
    while (!scanf("%f", &x) || x < min || getchar() != '\n') {
            error_();
            rewind(stdin);
    }
    return x;
}

double getdoubleMin (int min) {
    double x;
    while (!scanf("%lf", &x) || x < min || getchar() != '\n') {
            error_();
            rewind(stdin);
    }
    return x;
}
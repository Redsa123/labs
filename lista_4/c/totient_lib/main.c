//
// Created by serhi on 12/9/2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "totient.h"

int main(int argc, char *argv[]) {
    printf("\n");
    for (int i = 1; i < argc; i++) {
        printf("totient(%s) = %d;\n",argv[i], totient(atoi(argv[i])));
    }
    printf("\n");
    return 0;
}
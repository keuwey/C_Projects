#include <stdio.h>

int main() {
#if __STDC_VERSION__ >= 202311L
    printf("Compilando com C23 ou mais recente.\n");
#elif __STDC_VERSION__ >= 201710L
    printf("Compilando com C17 ou mais recente.\n");
#elif __STDC_VERSION__ >= 201112L
    printf("Compilando com C11.\n");
#elif __STDC_VERSION__ >= 199901L
    printf("Compilando com C99.\n");
#else
    printf("Compilando com C89/C90 ou anterior.\n");
#endif
    return 0;
}

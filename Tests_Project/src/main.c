#include <stdio.h>

int main() {
    int vector[5];

    for (int i = 0; i < 5; i++) {
        printf("Insira um numero:\n");
        scanf("%d", &vector[i]);
        fflush(stdin);
    }

    printf("Dados inseridos:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    return 0;
}
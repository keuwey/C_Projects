#include <math.h>
#include <stdio.h>

int main() {
  double a, b, c, r1, r2, delta;
  printf("Digite o valor de 'a':\n");
  scanf("%lf", &a);
  printf("Digite o valor de 'b':\n");
  scanf("%lf", &b);
  printf("Digite o valor de 'c':\n");
  scanf("%lf", &c);

  if (a == 0) {
    printf("O valor de 'a' nao pode ser zero.\n");
    return 1;
  }

  delta = b * b - 4 * a * c;
  if (delta > 0) {
    r1 = (-b + sqrt(delta)) / (2 * a);
    r2 = (-b - sqrt(delta)) / (2 * a);

    printf("As raizes da equacao sao: %.2f e %.2f\n", r1, r2);

    return 0;
  } else if (delta == 0) {
    r1 = -b / (2 * a);
    printf("A raiz da equacao e: %.2f\n", r1);
    return 0;
  } else {
    printf("A equacao nao possui raizes reais.\n");
    return 1;
  }
}

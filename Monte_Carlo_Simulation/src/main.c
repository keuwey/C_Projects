#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long double monteCarloPi(uint64_t n_iteracoes) {
    uint64_t dentro_circulo = 0;
    double x, y;

    for (uint64_t i = 0; i < n_iteracoes; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1.0) dentro_circulo++;
    }

    long double resultado = (4.0L * (long double)dentro_circulo) / (long double)n_iteracoes;
    return (long double)resultado;
}

int main(void) {
    uint64_t n_iteracoes = 900000000ULL;  // 100 milhões

    srand((unsigned)time(NULL));

    long double pi_estimado = monteCarloPi(n_iteracoes);

    printf("Estimativa de PI com %" PRIu64 " iteracoes: %.15Lf\n", n_iteracoes, pi_estimado);

    return 0;
}

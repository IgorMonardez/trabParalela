#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int primo (long int n) { /* mpi_primos.c  */
    int i;

    for (i = 3; i < (int)(sqrt(n) + 1); i+=2) {
        if(n%i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    double t_inicio, t_fim;
    int threads;
    long int i, n, total=0;

    if (argc < 2) {
        printf("Valor inválido! Entre com o valor do maior inteiro\n");
        return 0;
    } else {
        n = strtol(argv[1], (char **) NULL, 10);
        threads = strtol(argv[2], (char **) NULL, 10);
    }
    t_inicio = omp_get_wtime();
#pragma omp parallel for reduction(+:total) schedule(dynamic,1000) num_threads(threads)
    for (i = 3; i <= n; i += 2)
        if(primo(i) == 1) total++;

    total += 1;    /* Acrescenta o dois, que também é primo */
    t_fim = omp_get_wtime();
    printf("Quant. de primos entre 1 e %ld: %ld \n", n, total);
    printf("Tempo de execução: %f \n", t_fim-t_inicio);
    return(0);
}

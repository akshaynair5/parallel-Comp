#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int i;
    float a[N], b[N];
    float dot_product = 0.0;

    for (i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
    }

    #pragma omp parallel for reduction(+:dot_product) private(i)
    for (i = 0; i < N; i++) {
        dot_product += a[i] * b[i]; 
    }

    printf("Dot product: %f\n", dot_product);

    return 0;
}
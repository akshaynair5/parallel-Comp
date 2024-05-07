#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main () {
    int i;
    float a[N], b[N], sum[N];

    for (i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
    }

    #pragma omp parallel for shared(a, b, sum) private (i)
    for (i = 0; i < N; i++) {
        sum[i] = a[i] + b[i];
    }

    for (i = 0; i < N; i++) {
        printf("sum[%d] = %f\n", i, sum[i]);
    }
}
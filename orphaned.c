#include <stdio.h>
#include <omp.h>

void compute_sum(int *a, int n, int *sum); 

int main() {
    int sum =  0;
    int a[100];

    for (int i = 0; i < 100; i++) {
        a[i] = i + 1;
    }

    #pragma omp parallel reduction(+:sum)
    for(int i = 0; i < 100; i++) {
        compute_sum(a, 100, &sum);
    }

    printf("sum: %d\n", sum);

    return 0;
}

void compute_sum(int *a, int n, int *sum) {
    #pragma omp for
    for (int i = 0; i < n; i++) {
        *sum += a[i];
    }
}
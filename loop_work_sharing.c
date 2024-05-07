#include <stdio.h>
#include <omp.h>

#define SIZE 10

int main() {
    int numbers[SIZE];
    int squares[SIZE];

    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }

    #pragma omp parallel for
    for(int i = 0; i < SIZE; i++) {
        squares[i] = numbers[i] * numbers[i];
        printf("Processed element %d\n", i);
    }

    return 0;
}

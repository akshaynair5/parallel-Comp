#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define M 256
#define N 256
#define P 256

void initialize_matrix(double matrix[M][N], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() / (double)RAND_MAX;
        }
    }
}

void print_matrix(double matrix[M][P], int rows, int cols){
    for (int i = 0; i < rows && i < 10; i++) {
        for (int j = 0; j < cols && j < 10; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiply(double A[M][N], double B[N][P], double C[M][P]){
    #pragma omp target teams distribute parallel for collapse(2) map(to:A[:M][:N], B[:N][:P]) map(from:C[:M][:P])
    for (int i = 0; i < M; i++){
        for (int j = 0; j < P; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    double A[M][N], B[N][P], C[M][P];

    initialize_matrix(A, M, N);
    initialize_matrix(B, N, P);

    matrix_multiply(A, B, C);

    printf("Resulting matrix C (portion):\n");
    print_matrix(C, M, P);

    return 0;
}
#include <stdio.h>
#include <omp.h>

#define SIZE 1000

int main() {
    int numbers[SIZE];
    int sum = 0, max = 0;
    
    // Initialize the array
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }
    
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            // Calculate the sum
            for (int i = 0; i < SIZE; i++) {
                #pragma omp atomic
                sum += numbers[i];
            }
            // Print the sum
            printf("Sum calculated: %d\n", sum);
        }
        
        #pragma omp section
        {
            // Calculate the max
            for (int i = 0; i < SIZE; i++) {
                #pragma omp critical
                {
                    if (numbers[i] > max) {
                        max = numbers[i];
                    }
                }
            }
            // Print the max
            printf("Max calculated: %d\n", max);
        }
    }
    
    // Print final results
    printf("Final Sum: %d, Max: %d\n", sum, max);
    
    return 0;
}

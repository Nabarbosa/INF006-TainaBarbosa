#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAM 1000000

void selection_sort(int *A, int size){
    for(int i = 0; i < size; i++){         // n
        int menor = i;                     // 1 * n
        for(int j = i + 1; j < size; j++){   // n * n
            if(A[j] < A[menor]){             // 1 * n * n
                menor = j;
            }
        }
        if(menor != i){                  // 1 * n * n
            int aux = A[menor];         // n
            A[menor] = A[i];            // n
            A[i] = aux;                 // n
        }
    }
}


// T(n) = n + n + n + n + n + (n * n) + (n * n) + (n * n)
// T(n) = n + n + n + n + n + (n² + n² + n²)
// T(n) = 5n + 3n²
// T(n) = O(n²)
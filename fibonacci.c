#include<stdio.h>

#define N 6

void fibonacci_interativo(){

}

// Revisar as funções recursivas

void fibonacci_recursivo(){   // O(n)
    int a = 0, b = 1;

    for(int i = 0; i < N; i++){
        int aux = a + b;
        a = b;
        b = aux;
        printf("%d", aux);
    }  
}

int main(){

    fibonacci_recursivo(N);

    return 0;
}
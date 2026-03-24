#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAM 6

void insertion_sort(int *A, int size){
    
}

void print_array(int * valores, int tam){
    printf("\n[");
    for(int i = 0; i < tam; i++){
        if(i < tam-1){
            printf("%d, ", valores[i]);    
        }
    }
    printf("%d]\n", valores[tam-1]);
}

int main(){
    srand(time(NULL));
    int * valores = malloc(TAM * sizeof(int)); // Retorna o endereço de memória
    
    for(int i = 0; i < TAM; i++){
        valores[i]= rand()%100; // Rand - gerar numeros aleatórios
    }
    print_array(valores, TAM);
    
    return 0;
}

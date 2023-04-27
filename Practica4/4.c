#include <stdio.h>
#include <stdlib.h>
void reseervar_memoria(int **arreglo);
void inicializar(int **arreglo, int dimF);


int main(){
    int max = INT16_MIN;
    int *arreglo;
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    reservar_memoria(&arreglo, n);
    inicializar(&arreglo, n);
    printf("Numeros: \n");
    for (int i = 0; i < n; i++){
        printf("%d \n", arreglo[i]);
    }
    for (int i = 0; i < n; i++){
        if (arreglo[i] > max) max = arreglo[i];
    }
    printf("El maximo es : %d \n", max);
    free(arreglo);
    return 0;
}

void reservar_memoria(int **arreglo, int dimF){
    *arreglo = (int *) malloc(dimF * sizeof(int));
}

void inicializar(int **arreglo, int dimF){
    for (int i = 0; i < dimF; i++){
        *arreglo[i] = rand();
    }
}
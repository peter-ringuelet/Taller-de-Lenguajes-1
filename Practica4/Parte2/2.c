#include <stdio.h>
#include <stdlib.h>

void reservar_memoria(double **, int);
void cargar_arreglo(double *, int);
void imprimir_arreglo(double *, int);
double promedio(double *, int);

int main(){
    double *arreglo = NULL;
    int n;
    printf("Ingrese la dimension de la matriz: ");
    scanf("%d", &n);
    reservar_memoria(&arreglo, n);
    cargar_arreglo(arreglo, n);
    imprimir_arreglo(arreglo, n);
    free(arreglo);
    return 0;
}

void reservar_memoria(double **arreglo, int n){
    *arreglo = (double *)malloc(n*sizeof(double));
}

void cargar_arreglo(double *arreglo, int n){
    double numero;
    for (int i = 0; i < n; arreglo++, i++){
        printf("Ingrese un numero: ");
        scanf("%lf", &numero);
        *arreglo = numero;
    }
}

void imprimir_arreglo(double * arreglo, int n){
    for (int i =0; i< n; arreglo++, i++){
        printf("Numero (%d): %f \n", (i+1),*arreglo);
    }
}

double promedio(double *arreglo, int n){
    double tot = 0;
}


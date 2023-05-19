#include <stdio.h>
#include <stdlib.h>

struct nodo {
    char dato[100];
    struct nodo * sig;
};

void inicializar(struct nodo**);
void agregarInicio(struct nodo **, char []);
void agregarFinal(struct nodo **, int);
int cantElementos(struct nodo * lista);
void imprimirElementos(struct nodo * lista);
void eliminarElementos(struct nodo ** lista);
void cargarLista(struct nodo ** lista);


int main(){
    struct nodo * lista;
    inicializar(&lista);
    cargarLista(&lista);
    printf("Lista 1: \n");
    imprimirElementos(lista);
    elimiarElemento(&lista, 1);
    printf("Lista Modificada: \n");
    imprimirElementos(lista);

    eliminarElementos(&lista);
    imprimirElementos(lista);

    return 0;
}

void inicializar( struct nodo ** lista){
    *lista = NULL;
}

void agregarInicio(struct nodo ** lista, char dato[]){
    struct nodo * nuevo = (struct nodo*) malloc(sizeof(struct nodo));
    nuevo->dato = dato;
    nuevo->sig = *lista;
    *lista = nuevo;
}

void agregarFinal(struct nodo ** lista, int dato){
    struct nodo * nuevo = (struct nodo *) malloc(sizeof(struct nodo));
    struct nodo * aux = *lista;
    if (*lista == NULL){
        agregarInicio(lista,dato);
    }
    else{
        while((aux)->sig != NULL){
            aux = aux-> sig;
        }
        nuevo->dato = dato;
        nuevo->sig = NULL;
        aux->sig = nuevo;
    }
}

int cantElementos(struct nodo * lista){
    int cant = 0;
    struct nodo *aux = lista;
    while(aux != NULL){
        aux = aux->sig;
        cant++;
    }
    return cant;
}

void imprimirElementos(struct nodo * lista){
    struct nodo * aux = lista;
    while(aux != NULL){
        printf("%d \n", aux->dato);
        aux = aux->sig;
    }
}

void eliminarElementos(struct nodo ** lista) {
    struct nodo *aux;

    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}

struct nodo * invertirLista(struct nodo * lista){
    struct nodo * invertida;
    inicializar(&invertida);
    while(lista != NULL){
        agregarInicio(&invertida, lista->dato);
        lista = lista->sig;
    }
    return invertida;
}

void cargarLista(struct nodo ** lista){
    char string[100];
    printf("Ingrese una palabra: ");
    scanf("%s", string);
    while(string != "ZZZ"){
        agregarInicio(lista,string);
        printf("Ingrese una palabra: ");
        scanf("%s", string);
    }
}

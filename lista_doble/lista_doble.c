#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    int valor;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

// Función para crear un nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error al asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->valor = valor;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final
void insertarFinal(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    Nodo* actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
    nuevoNodo->anterior = actual;
}

// Función para imprimir la lista en ambos sentidos
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    printf("Lista en orden: ");
    while (actual != NULL) {
        printf("%d -> ", actual->valor);
        if (actual->siguiente == NULL) break;
        actual = actual->siguiente;
    }
    printf("NULL\n");

    printf("Lista en reversa: ");
    while (actual != NULL) {
        printf("%d -> ", actual->valor);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

// Función principal para pruebas
int main() {
    Nodo* lista = NULL;

    insertarFinal(&lista, 10
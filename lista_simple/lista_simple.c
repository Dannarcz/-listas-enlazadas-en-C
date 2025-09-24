#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    int valor;
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
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al inicio
void insertarInicio(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
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

    insertarInicio(&lista, 10);
    insertarInicio(&lista, 20);
    insertarInicio(&lista, 30);

    printf("Lista simplemente enlazada:\n");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}

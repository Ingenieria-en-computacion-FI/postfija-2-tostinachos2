#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pila.h"

Pila* crearPila() {
    Pila* p = (Pila*) malloc(sizeof(Pila));
    if (p == NULL) return NULL;
    p->tope = NULL;
    return p;
}

void push(Pila* p, void *dato, size_t size){
    if(p == NULL) return;

    NodoPila* nuevo = (NodoPila*) malloc(sizeof(NodoPila));
    if(nuevo == NULL) return;

    nuevo->dato = malloc(size);

    if(nuevo->dato == NULL){
        free(nuevo);
        return;
    }

    memcpy(nuevo->dato, dato, size);

    nuevo->siguiente = p->tope;
    p->tope = nuevo;
}

char pop(Pila* p){
    if (p==NULL|| p->tope == NULL) return '\0';

    NodoPila* temp = p->tope;
    char valor = *((char*) temp ->dato);

    p->tope=temp->siguiente;

    free(temp->dato);
    free(temp);

    return valor;
}

char peek(Pila* p) {
    if (p == NULL || p->tope == NULL) return '\0';
    return *((char*) p->tope->dato);
}

int pilaVacia(Pila* p) {
    return (p == NULL || p->tope == NULL);
}

void destruirPila(Pila* p) {
    if (p == NULL) return;
    while (!pilaVacia(p)) {
        pop(p);
    }
    free(p);
}

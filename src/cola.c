#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cola.h"

Cola* crearCola(){
    Cola* c=(Cola*)malloc(sizeof(Cola));
    if(c==NULL)return NULL;
    c->frente=NULL;
    c->final=NULL;
    return c;
}

void enqueue(Cola* c,void *dato,size_t size){
    if(c==NULL)return;
    NodoCola* nuevo=(NodoCola*)malloc(sizeof(NodoCola));
    if(nuevo==NULL)return;
    nuevo->dato=malloc(size);
    if(nuevo->dato==NULL){
        free(nuevo);
        return;
    }
    memcpy(nuevo->dato,dato,size);
    nuevo->siguiente=NULL;
    if(c->final==NULL){
        c->frente=nuevo;
        c->final=nuevo;
    }else{
        c->final->siguiente=nuevo;
        c->final=nuevo;
    }
}

char dequeue(Cola* c){
    if(c==NULL||c->frente==NULL)return'\0';
    NodoCola* temp=c->frente;
    char valor=*((char*)temp->dato);
    c->frente=temp->siguiente;
    if(c->frente==NULL){
        c->final=NULL;
    }
    free(temp->dato);
    free(temp);
    return valor;
}

int colaVacia(Cola* c){
    return(c==NULL||c->frente==NULL);
}

void imprimirCola(Cola* c){
    if(c==NULL||c->frente==NULL)return;
    NodoCola* actual=c->frente;
    while(actual!=NULL){
        printf("%c",*((char*)actual->dato));
        actual=actual->siguiente;
    }
    printf("\n");
}

void destruirCola(Cola* c){
    if(c==NULL)return;
    while(!colaVacia(c)){
        dequeue(c);
    }
    free(c);
}

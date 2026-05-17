#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "../include/evaluator.h"
#include "../include/pila.h"
#include "../include/cola.h"
#include "../include/parser.h"

float obtenerValorVariable(
    Variable variables[],
    int totalVariables,
    char nombre
){
    int i;

    for(i = 0; i < totalVariables; i++){
        if(variables[i].nombre == nombre){
            return variables[i].valor;
        }
    }

    return 0;
}

float sacarFloat(Pila* p){

    NodoPila* temp;
    float valor;

    if(pilaVacia(p)){
        return 0;
    }

    temp = p->tope;
    valor = *((float*)temp->dato);

    p->tope = temp->siguiente;

    free(temp->dato);
    free(temp);

    return valor;
}

float evaluarPostfija(
    Cola* postfija,
    Variable variables[],
    int totalVariables
){
    Pila* p;
    NodoCola* actual;
    char c;
    float a;
    float b;
    float res;
    float valorFinal;

    p = crearPila();
    actual = postfija->frente;

    while(actual != NULL){

        c = *((char*)actual->dato);

        if(isalpha(c)){

            res = obtenerValorVariable(
                variables,
                totalVariables,
                c
            );

            push(p, &res, sizeof(float));
        }

        else{

            b = sacarFloat(p);
            a = sacarFloat(p);
            res = 0;

            if(c == '+'){
                res = a + b;
            }
            else if(c == '-'){
                res = a - b;
            }
            else if(c == '*'){
                res = a * b;
            }
            else if(c == '/'){
                res = a / b;
            }
            else if(c == '^'){
                res = pow(a, b);
            }

            push(p, &res, sizeof(float));
        }

        actual = actual->siguiente;
    }

    valorFinal = sacarFloat(p);

    destruirPila(p);

    return valorFinal;
}
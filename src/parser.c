#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/parser.h"
#include "../include/pila.h"
#include "../include/cola.h"

int precedencia(char op){
    if(op == '^'){
        return 3;
    }

    if(op == '*' || op == '/'){
        return 2;
    }

    if(op == '+' || op == '-'){
        return 1;
    }

    return 0;
}

int esOperador(char c){
    return (
        c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '^'
    );
}

void cargarArchivo(
    const char* nombreArchivo,
    Variable variables[],
    int* totalVariables,
    char expresion[]
){
    FILE* archivo;
    char linea[256];
    char letra;
    float numero;

    archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL){
        return;
    }

    *totalVariables = 0;

    while(fgets(linea, sizeof(linea), archivo)){

        if(strchr(linea, '=')){

            sscanf(linea, " %c = %f", &letra, &numero);

            variables[*totalVariables].nombre = letra;
            variables[*totalVariables].valor = numero;

            (*totalVariables)++;
        }

        else if(strlen(linea) > 1){

            linea[strcspn(linea, "\n")] = '\0';
            strcpy(expresion, linea);
        }
    }

    fclose(archivo);
}

Cola* infijaAPostfija(char* expresion){

    Cola* salida;
    Pila* operadores;
    int i;
    char c;
    char op;

    salida = crearCola();
    operadores = crearPila();

    i = 0;

    while(expresion[i] != '\0'){

        c = expresion[i];

        if(isspace(c)){
            i++;
            continue;
        }

        if(isalpha(c)){
            enqueue(salida, &c, sizeof(char));
        }

        else if(c == '('){
            push(operadores, &c, sizeof(char));
        }

        else if(c == ')'){

            while(
                !pilaVacia(operadores) &&
                peek(operadores) != '('
            ){
                op = pop(operadores);
                enqueue(salida, &op, sizeof(char));
            }

            if(!pilaVacia(operadores)){
                pop(operadores);
            }
        }

        else if(esOperador(c)){

            while(
                !pilaVacia(operadores) &&
                peek(operadores) != '(' &&
                (
                    precedencia(peek(operadores)) > precedencia(c)
                    ||
                    (
                        precedencia(peek(operadores)) == precedencia(c)
                        && c != '^'
                    )
                )
            ){
                op = pop(operadores);
                enqueue(salida, &op, sizeof(char));
            }

            push(operadores, &c, sizeof(char));
        }

        i++;
    }

    while(!pilaVacia(operadores)){
        op = pop(operadores);
        enqueue(salida, &op, sizeof(char));
    }

    destruirPila(operadores);

    return salida;
}
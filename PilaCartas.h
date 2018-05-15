//
// Created by Ferran Salvat on 2/5/18.
//

#ifndef BLACKJACK_PILACARTAS_H
#define BLACKJACK_PILACARTAS_H


typedef struct N {
    int elemento;
    struct N *sig;
}Nodo;

typedef Nodo *Pila;

Pila PILA_crea();
void PILA_push(Pila *p, int elemento);
void PILA_pop(Pila *p);
int PILA_top(Pila p);
int PILA_vacia(Pila p);
void PILA_destruye(Pila *p);


#endif //BLACKJACK_PILACARTAS_H

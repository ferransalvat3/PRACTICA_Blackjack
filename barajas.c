//
// Created by Ferran Salvat on 14/5/18.
//
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "barajas.h"
#include "PilaCartas.h"



Baralles barallaCrea(int numbaralles){
    Baralles c;
    int i = 0, j=0;
    int barallaRand;
    int *barallaOrd;

    c.p = PILA_crea();
    int baralla[13] = {1,2,3,4,5,6,7,8,9,10,10,10,11};
    c.numCartes = numbaralles * 13;

    barallaOrd = (int*)malloc(sizeof(int)*c.numCartes);
    for (i=0; i<c.numCartes; i++){
        barallaOrd[i] = baralla[i % 13];
    }



    srand(time(NULL));
    for (i=0; i<c.numCartes; i++){
        barallaRand = rand() % (c.numCartes);

        PILA_push(&c.p, barallaOrd[barallaRand]);
    }

    return c;

}

int dameCarta(Baralles *c){
    int carta;

    if (!PILA_vacia(c->p)){
        carta = PILA_top(c->p);
        PILA_pop(&c->p);
        return carta;
    }else {
        return 0;
    }

}



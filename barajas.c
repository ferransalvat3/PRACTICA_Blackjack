//
// Created by Ferran Salvat on 14/5/18.
//

#include "barajas.h"
#include "PilaCartas.h"


Baralles barallaCrea(int numbaralles, Pila *p){
    Baralles b;
    int i = 0, j=0;
    int barallaRand;

    b.p = PILA_crea();
    int baralla[13] = {1,2,3,4,5,6,7,8,9,10,10,10,11};
    b.numCartes = numbaralles * 13;
    int barallaOrd[b.numCartes];

    for (i=0; i<numbaralles; i++){
        barallaOrd[j] = baralla[i];
        j++;
    }

    srand (time(NULL));
    for (i=0; i<b.numCartes; i++){
        barallaRand = rand() % (b.numCartes);
        PILA_push(*b.p, barallaOrd[barallaRand]);
    }

    return b;

}


int dameCarta(Baralles *b){

    if (PILA_vacia(b.p)){
        return PILA_pop(b.p);
    }else {
        return 0;
    }



}
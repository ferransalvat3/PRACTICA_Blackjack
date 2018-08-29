
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "barajas.h"


Baralles barallaCrea(int numbaralles){
    Baralles c;
    int i = 0;
    int barallaRand;
    int *barallaOrd;
    int barallaFin[260];


    c.p = PILA_crea();

    int baralla[52] = {2,3,4,5,6,7,8,9,10,'J','Q','K','A', 2,3,4,5,6,7,8,9,10,'J','Q','K','A', 2,3,4,5,6,7,8,9,10,'J','Q','K','A', 2,3,4,5,6,7,8,9,10,'J','Q','K','A'};

    for(i=0;i<numbaralles*52;i++){
        barallaFin[i]=baralla[i];
    }


    c.numCartes = numbaralles * 52;
    barallaOrd = (int *) malloc(sizeof(int) * c.numCartes);
    for (i = 0; i < c.numCartes; i++) {
        barallaOrd[i] = baralla[i % 52];
    }



    srand(time(NULL));

    for (i = 0; i < c.numCartes; i++) {
        barallaRand = rand() % (numbaralles*52);

        if (barallaFin[barallaRand] != 0){
            PILA_push(&c.p, barallaFin[barallaRand]);
            barallaFin[barallaRand] = 0;
        }else{
            i--;
        }
    }


    return c;

}

int dameCarta(Baralles *c){
    int carta;

    if (PILA_vacia(c->p)){
        *c = barallaCrea(c->numCartes/52);
        printf("\n\n\nBARAJA REGENERADA\n\n\n");
    }
    carta = PILA_top(c->p);
    PILA_pop(&c->p);
    if (carta == 'J' || carta == 'Q' || carta == 'K') {
        return 10;
    }else if(carta == 'A'){
        return 1;
    }
    return carta;

}

int BARAJA_vacia(Baralles *c) {
    return c == NULL;
}




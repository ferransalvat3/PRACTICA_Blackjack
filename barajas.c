
#include <stdlib.h>
#include <time.h>
#include "barajas.h"



Baralles barallaCrea(int numbaralles){
    Baralles c;
    int i = 0;
    int barallaRand;
    int *barallaOrd;

    c.p = PILA_crea();

    int baralla[52] = {2,3,4,5,6,7,8,9,10,'J','Q','K','A'};


            c.numCartes = numbaralles * 52;
            barallaOrd = (int *) malloc(sizeof(int) * c.numCartes);
            for (i = 0; i < c.numCartes; i++) {
                barallaOrd[i] = baralla[i % 13];
            }

            srand(time(NULL));
            for (i = 0; i < c.numCartes; i++) {
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
            if (carta == 'J' || carta == 'Q' || carta == 'K') {
                return 10;
            }else if(carta == 'A'){
                return 1;
            }
        return carta;

    }else {
        return 0;
    }

}

int BARAJA_vacia(Baralles *c) {
    return c == NULL;
}



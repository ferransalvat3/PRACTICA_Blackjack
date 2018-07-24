

#ifndef BLACKJACK_BARAJAS_H
#define BLACKJACK_BARAJAS_H
#include "PilaCartas.h"


typedef struct{
    Pila p;
    int numCartes;
}Baralles;


Baralles barallaCrea(int numbaralles);
int dameCarta(Baralles *b);

#endif //BLACKJACK_BARAJAS_H

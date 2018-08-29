
#include <stdlib.h>
#include "menu.h"



void main() {
    int opcion = 0;
    Bot *arrayBots= malloc(sizeof(Bot)*returnNumBots());
    Crupier c;
    Baralles baralles;
    menuPrincipal(opcion, arrayBots, c, baralles);

}




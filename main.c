
#include <stdlib.h>
#include "menu.h"



void main() {
    int opcion = 0;
    Bot *arrayBots= (Bot*)malloc(sizeof(Bot)*returnNumBots());

   menuPrincipal(opcion, arrayBots);
}




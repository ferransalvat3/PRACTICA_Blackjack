
#include <stdlib.h>
#include "menu.h"



void main() {
    int opcion = 0;
    int numeroDeBots=0;
    numeroDeBots=returnNumBots();
    Bot *arrayBots=(Bot*)malloc(sizeof(Bot)*numeroDeBots);
    Crupier c;
    Baralles baralles;
    menuPrincipal(opcion, arrayBots, c, baralles);

}





#include <malloc.h>
#include "menu.h"
#include "bot.h"


void main() {
    int opcion = 0;
    Bot *arrayBots= (Bot*)malloc(sizeof(Bot)*returnNumBots());

   menuPrincipal(opcion, arrayBots);
}




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "jugador.h"
#include "bot.h"
#include "comprobaciones.h"


void main() {
    Jugador j;
    Baralles c;
    int numbaralles = 0;

    j.fichas = 50;
    j.manos_ganadas=8;
    j.manos_perdidas=7;
    j.manos_empatadas=6;

    printf("Indica el numero de barajas:\n");
    scanf("%d", &numbaralles);

    while (numbaralles<1 || numbaralles>4){
        printf("No se pueden crear tantas barajas(1-4). Introduce un numero valido.\n");
        scanf("%d", &numbaralles);
    }
    c = barallaCrea(numbaralles);

    jugadorContraCrupier(c,j);



}




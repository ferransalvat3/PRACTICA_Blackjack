#include <stdio.h>
#include "jugador.h"
#include "partida.h"


void main() {
    Jugador j;
    Baralles c;
    int numbaralles = 0;



    printf("Indica el numero de barajas:\n");
    scanf("%d", &numbaralles);

    while (numbaralles<1 || numbaralles>4){
        printf("No se pueden crear tantas barajas(1-4). Introduce un numero valido.\n");
        scanf("%d", &numbaralles);
    }
    c = barallaCrea(numbaralles);

    j=ficherojugador();


    partida(c,j);



}




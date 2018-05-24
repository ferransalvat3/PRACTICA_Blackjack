#include <stdio.h>
#include "jugador.h"
#include "partida.h"
#include "bot.h"


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
    if (numbaralles>1 || numbaralles<4 ){
        printf("La baralla se ha creado correctamente\n");
    }
    c = barallaCrea(numbaralles);

    ficherobot();
    j=ficherojugador();


    partida(c,j);





}




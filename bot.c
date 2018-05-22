//
// Created by Ferran Salvat on 2/5/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bot.h"
#include "barajas.h"
#include "comprobaciones.h"
#include "mesa.h"

int apuestaDebil=100;
int apuestaNormal=500;
int apuestaFuerte=900;
Bot *arrayBots;
int numeroBots=3;

int retornaCartaMaxima(int idBot, Bot b){
    return b.cartaMaxima;
}

int retornaApuesta(Bot b){
        if (strcmp(b.caracter, "debil") == 0) {
            if(b.fichas>=20){
                if(b.fichas>apuestaDebil){
                    return apuestaDebil;
                } else{
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (strcmp(b.caracter, "normal") == 0) {
            if(b.fichas>=20){
                if(b.fichas>apuestaNormal){
                    return apuestaNormal;
                } else{
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (strcmp(b.caracter, "fuerte") == 0) {
            if(b.fichas>=20){
                if(b.fichas>apuestaFuerte){
                    return apuestaFuerte;
                } else{
                    return 0;
                }
            } else {
                return 0;
            }
        }

}

int pedirCartasSegunCaracter(int manoMasAlta, Bot b, int ultimaCarta){
    if (strcmp(b.caracter, "normal") == 0){
        if(b.puntuacionCartasBot<15 && ultimaCarta%2==0){
            return 1;
        } else{
            return 0;
        }
    } else if (strcmp(b.caracter, "debil") == 0){
        if(b.puntuacionCartasBot<=12){
            if(ultimaCarta<=2){
                return 1;
            }else {
                return 0;
            }
        } else{
            return 0;
        }

    } else if (strcmp(b.caracter, "fuerte") == 0){
        if(manoMasAlta ==0){
            if(b.puntuacionCartasBot<16){
                return 1;
            }
        } else{
            if(b.puntuacionCartasBot<manoMasAlta){
                return 1;
            } else{
                return 0;
            }
        }

    }
}
void turnoBots(int manoMasAlta, Baralles *c){
    Bot b;
    //Bot *arrayBots;
    int i=0;
    int numeroBots=3;
    int ii=0;
    int ultimaCarta=0;
    int turnoBot=0;
    arrayBots= (Bot*)malloc(sizeof(Bot)*numeroBots);

    // Simulacion de crear bots, borrar despues
    strcpy(arrayBots[0].caracter, "debil");
    arrayBots[0].fichas=900;
    strcpy(arrayBots[1].caracter, "fuerte");
    arrayBots[1].fichas=9;
    strcpy(arrayBots[2].caracter, "normal");
    arrayBots[2].fichas=904;
    //---------

    for (i = 0; i <numeroBots ; i++) {
        if (retornaApuesta(arrayBots[i])==0){
            printf("\nEl bot %i no puede apostar", i);
        } else{
            arrayBots[i].apuestaBot=retornaApuesta(arrayBots[i]);
            printf("\nEl bot %i apuesta: %i", i, arrayBots[i].apuestaBot);
        }
    }

    for (i=0;i<numeroBots;i++){
        arrayBots[i].puntuacionCartasBot=0;
        for (ii=0;ii<2;ii++){
            arrayBots[i].manobot[ii]=dameCarta(c);
            arrayBots[i].puntuacionCartasBot= arrayBots[i].puntuacionCartasBot+arrayBots[i].manobot[ii];
        }

        printf("\nEl bot %i tiene en la mano un %i y un %i", i,arrayBots[i].manobot[0],arrayBots[i].manobot[1]);
        printf(" Resultado bot: %i", arrayBots[i].puntuacionCartasBot);

        if (compruebaBlackJack(arrayBots[i].puntuacionCartasBot)==1){
            printf("El bot %i ha hecho blackjack a la primera", i);
            arrayBots[i].puedeGanar=1;
        }

    }

    i=0;
    ii=0;
    while (turnoBot<numeroBots) {
        if (turnoBot < numeroBots) {
            ultimaCarta = dameCarta(c);

            if (pedirCartasSegunCaracter(manoMasAlta, arrayBots[i], ultimaCarta) == 1) {
                arrayBots[i].puntuacionCartasBot = arrayBots[i].puntuacionCartasBot + ultimaCarta;
                manoMasAlta = comprobarManoMasAlta(arrayBots[i].puntuacionCartasBot, manoMasAlta);
            } else {
                if(compruebaBlackJack(arrayBots[i].puntuacionCartasBot)==1 || teHasPasado(arrayBots[i].puntuacionCartasBot)==0){
                    arrayBots[i].puedeGanar=1;
                }
                printf("\nEl bot %i pasa de turno", i);
                printf("\nEl bot %i tiene una puntuacion de %i", i, arrayBots[i].puntuacionCartasBot);
                i++;
                turnoBot++;
            }

        }

    }
}

void compruebaBotGanador(int resultadoCrupier){
    int i=0;
    for (i=0;i<numeroBots;i++) {
        if (arrayBots[i].puedeGanar==1 && arrayBots[i].puntuacionCartasBot > resultadoCrupier) {
            arrayBots[i].victorias = arrayBots[i].victorias + 1;
            arrayBots[i].fichas = arrayBots[i].fichas + (arrayBots[i].fichas * 2);
            printf("El bot %i ha ganado esta ronda", i);
        }
    }
}




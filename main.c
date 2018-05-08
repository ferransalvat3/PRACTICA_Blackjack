#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "jugador.h"
#include "bot.h"
#include "PilaCartas.h"
#include "comprobaciones.h"
#include "mesa.h"

void main() {
    Jugador j;
    Bot b;
    strcpy(j.nombre,"fefe");
    char respuesta[2];
    int posicionmano=2;
    int mano [10];
    int manocroupier [10];
    int resultado=0;
    int resultadoCroupier=0;
    int partidaEnJuego=1;
    int noSePidenMasCartas=0;

    j.fichas = 50;
    j.manos_ganadas=8;
    j.manos_perdidas=7;

    strcpy(b.nombre,"bot1");
    b.fichas = 5000;
    strcpy(b.caracter,"fuerte");
    b.cartaMaxima= 6;
    b.numero =1;

    //printf("Partidas ganadas: %d", retornaPartidasGanadas(j));
    //printf("carta maxima bot: %d", retornaCartaMaxima(b.numero, b));


    srand(time(NULL));
    mano[0]= dameCarta();
    resultado = mano[0];
    mano[1] = dameCarta();
    resultado = resultado + mano[1];

    printf("En la mano tienes un: %i y un %i", mano[0], mano[1]);

    manocroupier[0]= 3;
    resultadoCroupier = resultadoCroupier+manocroupier[0];
    manocroupier[1]= 11;
    resultadoCroupier = resultadoCroupier+manocroupier[1];



    int i=0;

    do{
        printf("\nQuieres pedir carta?");
        gets(respuesta);
        if (strcmp("no", respuesta) !=0) {
            posicionmano++;
            mano[posicionmano - 1] = dameCarta();
            manocroupier[posicionmano - 1] = dameCarta();
            resultado = resultado + mano[posicionmano - 1];
            resultadoCroupier = resultadoCroupier + manocroupier[posicionmano - 1];
            for (i = 0; i < posicionmano; i++) {
                printf("En la mano tienes:%i\n", mano[i]);
            }
            for (i = 0; i < posicionmano; i++) {
                printf("El crupier en la mano tiene:%i\n", manocroupier[i]);
            }
            printf("\nTienes un valor de %i", resultado);
            if (compruebaBlackJack(resultado) == 1) {
                printf("\nENHORABUENA! TIENES BLACKJACK!");
                noSePidenMasCartas=1;
                partidaEnJuego=0;
            }
            if (teHasPasado(resultado) == 1) {
                printf("\nTe has pasado, loser");
                noSePidenMasCartas=1;
                partidaEnJuego=0;
            }
            if (teHasPasado(resultadoCroupier) == 1) {
                printf("\nEl croupier se ha pasado, enhorabuena has ganado");
                noSePidenMasCartas=1;
                partidaEnJuego=0;
            }
        } else{
            partidaEnJuego =0;
        }

    }while (partidaEnJuego!=0);

    if(noSePidenMasCartas ==0) {
        if (teHasPasado(resultado) == 0 && compruebaBlackJack(resultado) == 0) {
            if (compruebaManos(resultado, resultadoCroupier) == 1) {
                printf("Gana la banca");
            } else if (compruebaManos(resultado, resultadoCroupier) == 2) {
                printf("Enhorabuena, has ganado");
                j.manos_ganadas = j.manos_ganadas + 1;
                printf("Tienes %i manos ganadas", j.manos_ganadas);
            } else {
                printf("Empate!");
            }
        }
    }


}
//
// Created by smoreno on 24/05/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mem.h>
#include "partida.h"
#include "bot.h"
#include "comprobaciones.h"
#include "jugador.h"


void jugadorContraCrupier(Baralles c, Jugador j){

    char respuesta[3];
    int posicionmano=2;
    int mano [10];
    int manocroupier [10];
    int resultado=0;
    int partidaEnJuego=1;
    int noSePidenMasCartas=0;
    int juegoCrupier=1;
    int resultadoCroupier=0;
    int apuestaJugador=0;
    int numbaralles = 0;
    int manoMasAlta=0;
    int i=0;

    srand(time(NULL));

    printf("Cuantas fichas vas a apostar?\n");
    scanf("%d", &apuestaJugador);
    while (compruebaFichasJugador(j, apuestaJugador)==0){
        printf("No puedes apostar, no tienes tantas fichas, indica una nueva cantidad\n");
        scanf("%d", &apuestaJugador);
    }

    j.fichas= j.fichas-apuestaJugador;
    mano[0]= dameCarta(&c);
    resultado = mano[0];
    mano[1] = dameCarta(&c);
    resultado = resultado + mano[1];

    turnoBots(manoMasAlta, &c);

    if (compruebaBlackJack(resultado) == 1) {
        printf("ENHORABUENA! TIENES BLACKJACK A LA PRIMERA!\n");
        noSePidenMasCartas=1;
        partidaEnJuego=0;
    }

    printf("Te quedan: %d fichas\n", retornaFichasJugador(j));
    printf("En la mano tienes un: %i y un %i\n", mano[0], mano[1]);

    manocroupier[0]= dameCarta(&c);
    resultadoCroupier = resultadoCroupier+manocroupier[0];
    manocroupier[1]= dameCarta(&c);
    resultadoCroupier = resultadoCroupier+manocroupier[1];

    if (compruebaBlackJack(resultadoCroupier) == 1) {
        //printf("el crupier ha hecho blackjack a la primera\n");
        //noSePidenMasCartas=1;
        //partidaEnJuego=0;
        juegoCrupier=0;
    }



    if (partidaEnJuego!=0) {
        do {
            printf("\nQuieres pedir carta?\n");
            scanf("%s", respuesta);
            if (strcmp("no", respuesta) != 0) {
                posicionmano++;
                mano[posicionmano - 1] = dameCarta(&c);
                resultado = resultado + mano[posicionmano - 1];
                for (i = 0; i < posicionmano; i++) {
                    printf("En la mano tienes:%i \n", mano[i]);
                }
                printf("Tienes un valor de %i\n", resultado);
                if (compruebaBlackJack(resultado) == 1) {
                    printf("ENHORABUENA! TIENES BLACKJACK!\n");
                    noSePidenMasCartas = 1;
                    partidaEnJuego = 0;
                }
                if (teHasPasado(resultado) == 1) {
                    printf("Te has pasado, loser\n");
                    noSePidenMasCartas = 1;
                    partidaEnJuego = 0;
                }
            } else {
                partidaEnJuego = 0;
            }

        } while (partidaEnJuego != 0);
    }


    posicionmano=2;
    if (juegoCrupier!=0) {
        printf("Turno del crupier\n");
        for (i = 0; i < posicionmano; i++) {
            printf("El crupier en la mano tiene:%i\n", manocroupier[i]);
        }
        do {
            if (juegoCrupier == 1) {
                //if (resultadoCroupier <= resultado) {
                if (resultadoCroupier < 17) {
                    posicionmano++;
                    manocroupier[posicionmano - 1] = dameCarta(&c);
                    resultadoCroupier = resultadoCroupier + manocroupier[posicionmano - 1];
                    printf("El crupier pide carta\n"
                                   "");
                    for (i = 0; i < posicionmano; i++) {

                        printf("El crupier en la mano tiene:%i\n", manocroupier[i]);
                    }
                    if (teHasPasado(resultadoCroupier) == 1) {
                        if (teHasPasado(resultado)==0){
                            printf("El croupier se ha pasado, has ganado\n");
                            j.manos_ganadas = j.manos_ganadas + 1;
                            printf("Tienes %i manos ganadas\n", j.manos_ganadas);
                        }
                        noSePidenMasCartas = 1;
                        juegoCrupier = 0;
                    }
                    if (compruebaBlackJack(resultadoCroupier) == 1) {
                        printf("Blackjack del crupier\n");
                        noSePidenMasCartas = 1;
                        juegoCrupier = 0;
                        break;
                    }
                    printf("El crupier tiene un valor de %i\n", resultadoCroupier);
                } else{
                    juegoCrupier=0;
                }
//                } else if (resultadoCroupier > resultado) {
//                    noSePidenMasCartas = 0;
//                    juegoCrupier = 0;
//                }
            }

        } while (juegoCrupier == 1);
    }

    printf("El crupier no pide mas");



    if(noSePidenMasCartas ==0) {
        if (teHasPasado(resultado) == 0 && compruebaBlackJack(resultado) == 0) {
            if (compruebaManos(resultado, resultadoCroupier) == 1) {
                printf("\nEl crupier te ha ganado\n");
                j.manos_perdidas= j.manos_perdidas+1;
                printf("Tienes %i manos perdidas\n", j.manos_perdidas);
            } else if (compruebaManos(resultado, resultadoCroupier) == 2) {
                printf("\nEnhorabuena, has ganado\n");
                j.manos_ganadas = j.manos_ganadas + 1;
                printf("Tienes %i manos ganadas\n", j.manos_ganadas);
            } else {
                printf("\nEmpate entre el crupier y tu\n");
                j.manos_empatadas= j.manos_empatadas+1;
                printf("Tienes %i manos empatadas\n", j.manos_empatadas);
            }
        }
    }

    compruebaBotGanador(resultadoCroupier);

}
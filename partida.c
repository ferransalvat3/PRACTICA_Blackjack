

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "partida.h"
#include "bot.h"
#include "comprobaciones.h"



void comprobaciones(Jugador j, int resultado, int resultadoCroupier){

    if (compruebaManos(resultado, resultadoCroupier) == 1) {
        if(teHasPasado(resultadoCroupier)==0) {
            printf("\nEl crupier te ha ganado\n");
            j.manos_perdidas = j.manos_perdidas + 1;
        }
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
void salidaJugador(int mano[10]){
    int i=0;
    printf("\nMano del jugador");
    for (i = 0; i < 10; i++) {
        if(mano[i]!=0) {
            printf("[%i]", mano[i]);

        }
    }
    printf("\n----------------------------");
}

void salidaCrupier(int manoCrupier[10]){
    int i=0;
    printf("\nMano del crupier");
    for (i = 0; i < 10; i++) {
        if(manoCrupier[i]!=0) {
            printf("[%i]", manoCrupier[i]);
        }
    }
    printf("\n----------------------------");
}

void partida(Baralles c, Jugador j, Bot *arrayBots, Crupier crupier){
    int posicionmano=2;
    int mano [10];
    int resultado=0;
    int manocroupier [10];
    int partidaEnJuego=1;
    int noSePidenMasCartas=0;
    int juegoCrupier=1;
    int resultadoCroupier=0;
    int apuestaJugador=0;
    int i;
    char respuesta[3];
    int manoMasAlta=0;


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

    printf("\nTe quedan: %d fichas\n", retornaFichasJugador(j));
    salidaJugador(mano);

    turnoBots(manoMasAlta, &c, arrayBots);

    if (compruebaBlackJack(resultado) == 1) {
        printf("ENHORABUENA! TIENES BLACKJACK A LA PRIMERA!\n");
        j.manos_ganadas = j.manos_ganadas + 1;
        noSePidenMasCartas=1;
        partidaEnJuego=0;
    }
    manocroupier[0]= dameCarta(&c);
    resultadoCroupier = resultadoCroupier+manocroupier[0];
    manocroupier[1]= dameCarta(&c);
    resultadoCroupier = resultadoCroupier+manocroupier[1];

    if (compruebaBlackJack(resultadoCroupier) == 1) {
        juegoCrupier=0;
        printf("El crupier ha hech Blackjack a la primera\n");
        salidaCrupier(manocroupier);
    }
    if (partidaEnJuego!=0) {
        do {
            printf("\nQuieres pedir carta?\n");
            scanf("%s", respuesta);
            if (strcmp("no", respuesta) != 0) {
                posicionmano++;
                mano[posicionmano - 1] = dameCarta(&c);
                resultado = resultado + mano[posicionmano - 1];
                salidaJugador(mano);
                printf("\nTienes un valor de %i\n", resultado);
                if (compruebaBlackJack(resultado) == 1) {
                    printf("ENHORABUENA! TIENES BLACKJACK!\n");
                    noSePidenMasCartas = 1;
                    partidaEnJuego = 0;
                }
                if (teHasPasado(resultado) == 1) {
                    printf("Te has pasado, loser\n");
                    j.manos_perdidas = j.manos_perdidas + 1;
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
        printf("TURNO DEL CRUPIER:\n");
        salidaCrupier(manocroupier);
        do {
            if (juegoCrupier == 1) {
                if (resultadoCroupier < 17) {
                    posicionmano++;
                    manocroupier[posicionmano - 1] = dameCarta(&c);
                    resultadoCroupier = resultadoCroupier + manocroupier[posicionmano - 1];
                    salidaCrupier(manocroupier);
                    if (teHasPasado(resultadoCroupier) == 1) {
                        if (teHasPasado(resultado)==0){
                            salidaCrupier(manocroupier);
                            printf("\nEl croupier se ha pasado, has ganado\n");
                            j.manos_ganadas = j.manos_ganadas + 1;
                            printf("\nTienes %i manos ganadas\n", j.manos_ganadas);
                        }
                        noSePidenMasCartas = 1;
                        juegoCrupier = 0;
                    }
                    if (compruebaBlackJack(resultadoCroupier) == 1) {
                        salidaCrupier(manocroupier);
                        printf("\nBlackjack del crupier\n");
                        if(compruebaBlackJack(resultado)==0){
                            printf("\nEl crupier te ha ganado");
                            j.manos_perdidas= j.manos_perdidas+1;
                        } else if(compruebaBlackJack(resultado)==1){
                            printf("\nEl crupier ha hecho blackjack igual que tu, empatais\n");
                            j.manos_empatadas= j.manos_empatadas;
                        }
                        comprobaciones(j, resultado,resultadoCroupier);
                        noSePidenMasCartas = 1;
                        break;
                    }
                    printf("\nEl crupier tiene un valor de %i\n", resultadoCroupier);
                } else{
                    juegoCrupier=0;
                }
            }

        } while (juegoCrupier == 1);
    }


    printf("\nEl crupier no pide mas\n");

    incrementaResultadoCrupier(resultadoCroupier, crupier);

    if(noSePidenMasCartas ==0) {
        if (teHasPasado(resultado) == 0 && compruebaBlackJack(resultado) == 0) {
            comprobaciones(j, resultado,resultadoCroupier);
        }
    }

    compruebaBotGanador(resultadoCroupier, arrayBots);
    escribirFichero (j);

}






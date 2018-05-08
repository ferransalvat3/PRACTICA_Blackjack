#include <stdio.h>
#include <string.h>
#include "jugador.h"
#include "bot.h"
#include "PilaCartas.h"
#include "comprobaciones.h"

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
    while (strcmp("no", respuesta) !=0){
        printf("\nQuieres pedir carta?");
        gets(respuesta);
        posicionmano ++;
        mano[posicionmano-1] = dameCarta();
        resultado = resultado + mano[posicionmano-1];
        for (i = 0; i < posicionmano; i++) {
            printf("En la mano tienes:%i\n", mano[i]);
        }
        printf("\nTienes un valor de %i", resultado);
        if(compruebaBlackJack(resultado)==1){
            printf("\nENHORABUENA! TIENES BLACKJACK!");
            break;
        }
        if(teHasPasado(resultado) ==1){
            printf("\nTe has pasado, loser");
            break;
        }

    }

    if(teHasPasado(resultado)==0 && compruebaBlackJack(resultado)==0){
        if(compruebaManos(resultado, resultadoCroupier)==1){
            printf("Gana la banca");
        } else if(compruebaManos(resultado, resultadoCroupier)==2){
            printf("Enhorabuena, has ganado");
        } else{
            printf("Empate!");
        }
    }


}
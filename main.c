#include <stdio.h>
#include <mem.h>
#include "jugador.h"
#include "bot.h"

void main() {
    Jugador j;
    Bot b;
    strcpy(j.nombre,"fefe");
    j.fichas = 50;
    j.manos_ganadas=8;
    j.manos_perdidas=7;

    strcpy(b.nombre,"bot1");
    b.fichas = 5000;
    strcpy(b.caracter,"fuerte");
    b.cartaMaxima= 6;
    b.numero =1;

    printf("Partidas ganadas: %d", retornaPartidasGanadas(j));
    printf("carta maxima bot: %d", retornaCartaMaxima(b.numero, b));


}
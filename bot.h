#ifndef BLACKJACK_BOT_H
#define BLACKJACK_BOT_H

#include "barajas.h"

typedef struct{
    int numero;
    char nombre[50];
    int fichas;
    char caracter[10];
    int cartaMaxima;
    int manobot[10];
    int puntuacionCartasBot;
    int apuestaBot;
    int victorias;
    int puedeGanar;
}Bot;


int retornaCartaMaxima(int idBot, Bot b);
int retornaApuesta(Bot b);
int pedirCartasSegunCaracter(int manoMasAlta, Bot b, int ultimaCarta);
void turnoBots(int manoMasAlta, Baralles *c);
void compruebaBotGanador(int resultadoCrupier);

#endif //BLACKJACK_BOT_H
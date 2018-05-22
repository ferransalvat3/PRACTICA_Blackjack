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
}Bot;


int retornaCartaMaxima(int idBot, Bot b);
int retornaApuesta(Bot b);
int pedirCartasSegunCaracter(int manoMasAlta, Bot b, int ultimaCarta);
void turnoBots(int manoMasAlta, Baralles *c);

#endif //BLACKJACK_BOT_H
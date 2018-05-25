#ifndef BLACKJACK_BOT_H
#define BLACKJACK_BOT_H

#include "barajas.h"

typedef struct{
    char nombre[50];
    int fichas;
    char caracter[10];
    int cartaMaxima;
    int manobot[10];
    int puntuacionCartasBot;
    int apuestaBot;
    int victorias;
    int derrotas;
    int empates;
    int puedeGanar;
    int noApuesta;
}Bot;


int retornaCartaMaxima(int idBot, Bot b);
int retornaApuesta(Bot b);
int pedirCartasSegunCaracter(int manoMasAlta, Bot b);
void turnoBots(int manoMasAlta, Baralles *c);
void compruebaBotGanador(int resultadoCrupier);
void ficherobot();
void estadisticasBot();

void print();

#endif //BLACKJACK_BOT_H
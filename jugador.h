

#ifndef BLACKJACK_JUGADOR_H
#define BLACKJACK_JUGADOR_H

#include "barajas.h"

typedef struct {
    char nombre[50];
    int fichas;
    int manos_ganadas;
    int manos_perdidas;
    int manos_empatadas;
}Jugador;


int retornaPartidasGanadas(Jugador j);
int compruebaFichasJugador(Jugador j, int fichas);
int retornaFichasJugador(Jugador j);
Jugador ficherojugador(Jugador j);
void estadisticasJugador(Jugador *j);
void escribirFichero (Jugador j);


#endif //BLACKJACK_JUGADOR_H

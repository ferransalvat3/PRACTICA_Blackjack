//
// Created by smoreno on 19/04/2018.
//

#ifndef BLACKJACK_JUGADOR_H
#define BLACKJACK_JUGADOR_H
typedef struct {
    char nombre[50];
    int fichas;
    int manos_ganadas;
    int manos_perdidas;
}Jugador;


int retornaPartidasGanadas(Jugador j);
int compruebaFichasJugador(Jugador j, int fichas);
int retornaFichasJugador(Jugador j);

#endif //BLACKJACK_JUGADOR_H

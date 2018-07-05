//
// Created by Ferran Salvat on 16/5/18.
//

#ifndef BLACKJACK_MENU_H
#define BLACKJACK_MENU_H


#include "jugador.h"
#include "bot.h"

int menuPrincipal(int opcion, Bot *arrayBots);
//int menuJugar(int opcion);
int menuEstadistica(int opcion, Jugador j, Bot *arrayBots);

#endif //BLACKJACK_MENU_H

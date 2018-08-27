

#ifndef BLACKJACK_MENU_H
#define BLACKJACK_MENU_H


#include "jugador.h"
#include "bot.h"
#include "crupier.h"

int menuPrincipal(int opcion, Bot *arrayBots, Crupier crupier, Baralles c);
int menuEstadistica(int opcion, Jugador j, Bot *arrayBots, Crupier crupier, Baralles baralles);

#endif //BLACKJACK_MENU_H

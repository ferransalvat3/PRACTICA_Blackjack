cmake_minimum_required(VERSION 3.8)
project(Blackjack)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c PilaCartas.c jugador.h jugador.c bot.h bot.c PilaCartas.h mesa.c mesa.h comprobaciones.c comprobaciones.h barajas.c barajas.h menu.c menu.h partida.c partida.h crupier.c crupier.h)
add_executable(Blackjack ${SOURCE_FILES})
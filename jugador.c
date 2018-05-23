#include <stdio.h>
#include <mem.h>
#include "jugador.h"
#include "mesa.h"
#include "comprobaciones.h"

int retornaPartidasGanadas(Jugador j){
    return j.manos_ganadas;
}

int compruebaFichasJugador(Jugador j, int fichas){
    if(j.fichas>=fichas){
        return 1;
    } else{
        return 0;
    }
}

int retornaFichasJugador(Jugador j){
    return j.fichas;
}


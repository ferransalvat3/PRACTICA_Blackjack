//
// Created by smoreno on 02/05/2018.
//


#include "bot.h"

int comprobarManoMasAlta(int valorQueSeComprueba, int manoMasAltaActual){
    if(valorQueSeComprueba>=manoMasAltaActual){
        return valorQueSeComprueba;
    } else{
        return manoMasAltaActual;
    }
}
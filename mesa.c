

#include "mesa.h"

int comprobarManoMasAlta(int valorQueSeComprueba, int manoMasAltaActual){
    if(valorQueSeComprueba>=manoMasAltaActual){
        return valorQueSeComprueba;
    } else{
        return manoMasAltaActual;
    }
}
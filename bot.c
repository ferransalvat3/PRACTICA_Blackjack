//
// Created by Ferran Salvat on 2/5/18.
//


#include <mem.h>
#include <stdlib.h>
#include "bot.h"

int apuestaDebil=100;
int apuestaNormal=500;
int apuestaFuerte=900;

int retornaCartaMaxima(int idBot, Bot b){
    return b.cartaMaxima;
}

int retornaApuesta(Bot b){
        if (strcmp(b.caracter, "debil") == 0) {
            if(b.fichas>=20){
                return apuestaDebil;
            } else {
                return 0;
            }
        } else if (strcmp(b.caracter, "normal") == 0) {
            if(b.fichas>=20){
                return apuestaNormal;
            } else {
                return 0;
            }
        } else if (strcmp(b.caracter, "fuerte") == 0) {
            if(b.fichas>=20){
                return apuestaFuerte;
            } else {
                return 0;
            }
        }

}
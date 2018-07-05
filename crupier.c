//
// Created by smoreno on 05/07/2018.
//

#include "crupier.h"

Crupier init0(){
    Crupier crupier;

    crupier.veces17=0;
    crupier.veces18=0;
    crupier.veces19=0;
    crupier.veces20=0;
    crupier.veces21=0;
    crupier.vecesMayor21=0;


    return crupier;
}

int retornaVeces17(Crupier c){
    return c.veces17;
}
int retornaVeces18(Crupier c){
    return c.veces18;
}
int retornaVeces19(Crupier c){
    return c.veces19;
}
int retornaVeces20(Crupier c){
    return c.veces20;
}
int retornaVeces21(Crupier c){
    return c.veces21;
}
int retornaVecesMayor21(Crupier c){
    return c.vecesMayor21;
}

void incrementaResultadoCrupier(int resultadoCrupier, Crupier c){
    switch (resultadoCrupier){
        case 17:
            c.veces17=c.veces17+1;
            break;
        case 18:
            c.veces18=c.veces18+1;
            break;
        case 19:
            c.veces19=c.veces19+1;
            break;
        case 20:
            c.veces20=c.veces20+1;
            break;
        case 21:
            c.veces21=c.veces21+1;
            break;

    }
    if(resultadoCrupier>21){
        c.vecesMayor21=c.vecesMayor21+1;
    }
}



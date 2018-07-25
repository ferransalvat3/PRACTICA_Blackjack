

#include "crupier.h"
#include <stdio.h>

Crupier init0(Crupier crupier){

    crupier.veces17=0;
    crupier.veces18=0;
    crupier.veces19=0;
    crupier.veces20=0;
    crupier.veces21=0;
    crupier.vecesMayor21=0;


    return crupier;
}



Crupier incrementaResultadoCrupier(int resultadoCrupier, Crupier c){
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
    return c;
}

void estadisticasCrupier(Crupier crupier){


    printf("igual 17:%i\n", crupier.veces17);
    printf("igual 18:%i\n", crupier.veces18);
    printf("igual 19:%i\n", crupier.veces19);
    printf("igual 20:%i\n", crupier.veces20);
    printf("igual 21:%i\n", crupier.veces21);
    printf("mayor 21:%i\n", crupier.vecesMayor21);


}



//
// Created by smoreno on 05/07/2018.
//

#ifndef BLACKJACK_CRUPIER_H
#define BLACKJACK_CRUPIER_H

typedef struct {
    int veces17;
    int veces18;
    int veces19;
    int veces20;
    int veces21;
    int vecesMayor21;
}Crupier;

int retornaVeces17(Crupier c);
int retornaVeces18(Crupier c);
int retornaVeces19(Crupier c);
int retornaVeces20(Crupier c);
int retornaVeces21(Crupier c);
int retornaVecesMayor21(Crupier c);
Crupier init0();
void incrementaResultadoCrupier(int resultadoCrupier, Crupier c);

#endif //BLACKJACK_CRUPIER_H

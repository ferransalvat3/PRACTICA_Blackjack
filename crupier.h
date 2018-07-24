

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

void estadisticasCrupier(Crupier crupier);
Crupier init0(Crupier crupier);
void incrementaResultadoCrupier(int resultadoCrupier, Crupier c);

#endif //BLACKJACK_CRUPIER_H

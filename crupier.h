

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

Crupier init0(Crupier crupier);
Crupier incrementaResultadoCrupier(int resultadoCrupier, Crupier c);
void estadisticasCrupier(Crupier *crupier);
void ficheroCrupier (Crupier crupier);

#endif //BLACKJACK_CRUPIER_H

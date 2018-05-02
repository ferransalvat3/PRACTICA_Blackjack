#ifndef BLACKJACK_BOT_H
#define BLACKJACK_BOT_H

typedef struct{
    int numero;
    char nombre[50];
    int fichas;
    char caracter[50];
    int cartaMaxima;
}Bot;


int retornaCartaMaxima(int idBot, Bot b);

#endif //BLACKJACK_BOT_H
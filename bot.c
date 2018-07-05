
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bot.h"
#include "comprobaciones.h"
#include "mesa.h"





void muestraCartasBots(int numBots, Bot *arrayBots){

    int i=0;
    int ii=0;

    for(i=0; i<numBots;i++){
        for(ii=0;ii<10;ii++){
            if(arrayBots[i].manobot[ii]>0 && arrayBots[i].manobot[ii]<22)
            printf("\nEl bot %s tiene en la mano %i",  arrayBots[i].nombre, arrayBots[i].manobot[ii]);
        }
    }
}

int retornaApuesta(Bot b){

    int apuestaDebil=100;
    int apuestaNormal=500;
    int apuestaFuerte=900;

        if (strcmp(b.caracter, "debil") == 0) {
            if(b.fichas>=20){
                if(b.fichas>apuestaDebil){
                    return apuestaDebil;
                } else{
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (strcmp(b.caracter, "normal") == 0) {
            if(b.fichas>=20){
                if(b.fichas>apuestaNormal){
                    return apuestaNormal;
                } else{
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (strcmp(b.caracter, "fuerte") == 0) {
            if(b.fichas>=20){
                if(b.fichas>apuestaFuerte){
                    return apuestaFuerte;
                } else{
                    return 0;
                }
            } else {
                return 0;
            }
        }

}

int pedirCartasSegunCaracter(int manoMasAlta, Bot b){
    if (strcmp(b.caracter, "normal") == 0){
        if(b.puntuacionCartasBot<15){
            return 1;
        } else{
            return 0;
        }
    } else if (strcmp(b.caracter, "debil") == 0){
        if(b.puntuacionCartasBot<12){
            return 1;
        } else{
            return 0;
        }

    } else if (strcmp(b.caracter, "fuerte") == 0){
        if(manoMasAlta ==0){
            if(b.puntuacionCartasBot<16){
                return 1;
            }
        } else{
            if(b.puntuacionCartasBot<manoMasAlta){
                return 1;
            } else{
                return 0;
            }
        }

    }
}

int comprobarCartasSegunCaracter(Bot b, int ultimaCarta){
    if (strcmp(b.caracter, "normal") == 0){
        if(ultimaCarta%2==0){
            return 1;
        } else{
            return 0;
        }
    } else if (strcmp(b.caracter, "debil") == 0) {
        if(ultimaCarta<2){
            return 1;
        } else{
            return 0;
        }
    }

}

void turnoBots(int manoMasAlta, Baralles *c, Bot *arrayBots){

    int i;
    int ii;
    int ultimaCarta;
    int turnoBot;
    for (i = 0; i <returnNumBots() ; i++) {
        if (retornaApuesta(arrayBots[i])==0){
            printf("\nEl bot %s no puede apostar", arrayBots[i].nombre);
            arrayBots[i].noApuesta=1;
        } else{
            arrayBots[i].noApuesta=0;
            arrayBots[i].apuestaBot=retornaApuesta(arrayBots[i]);
            arrayBots[i].fichas= arrayBots[i].fichas-arrayBots[i].apuestaBot;
            printf("\nEl bot %s apuesta: %i", arrayBots[i].nombre, arrayBots[i].apuestaBot);
        }
    }

    for (i=0;i<returnNumBots();i++){
        if(arrayBots[i].noApuesta==0) {
            arrayBots[i].puntuacionCartasBot = 0;
            for (ii = 0; ii < 2; ii++) {
                arrayBots[i].manobot[ii] = dameCarta(c);
                arrayBots[i].puntuacionCartasBot = arrayBots[i].puntuacionCartasBot + arrayBots[i].manobot[ii];
            }

            printf("\nEl bot %s tiene en la mano un %i y un %i",  arrayBots[i].nombre, arrayBots[i].manobot[0], arrayBots[i].manobot[1]);
            printf(" Resultado bot: %i", arrayBots[i].puntuacionCartasBot);

        }

    }

    i=0;
    ii=2;
    while (turnoBot<returnNumBots()) {
        if(arrayBots[i].noApuesta==0) {
            if (turnoBot < returnNumBots()) {
                ultimaCarta = dameCarta(c);
                if (pedirCartasSegunCaracter(manoMasAlta, arrayBots[i]) == 1) {
                    arrayBots[i].puntuacionCartasBot = arrayBots[i].puntuacionCartasBot + ultimaCarta;
                    arrayBots[i].manobot[ii] = ultimaCarta;
                    ii++;
                    manoMasAlta = comprobarManoMasAlta(arrayBots[i].puntuacionCartasBot, manoMasAlta);
                    if (comprobarCartasSegunCaracter(arrayBots[i], ultimaCarta) == 0) {
                        printf("\nEl bot %s pasa de turno",  arrayBots[i].nombre);
                        printf("\nEl bot %s tiene una puntuacion de %i",  arrayBots[i].nombre, arrayBots[i].puntuacionCartasBot);
                        i++;
                        turnoBot++;
                    }

                } else {
                    if (teHasPasado(arrayBots[i].puntuacionCartasBot) == 1) {
                        arrayBots[i].puedeGanar = 1;
                    }
                    printf("\nEl bot %s pasa de turno",  arrayBots[i].nombre);
                    printf("\nEl bot %s tiene una puntuacion de %i",  arrayBots[i].nombre, arrayBots[i].puntuacionCartasBot);
                    i++;
                    turnoBot++;
                }

            }
        } else{
            i++;
            turnoBot++;
        }
    }

    muestraCartasBots(returnNumBots(), arrayBots);
}

void compruebaBotGanador(int resultadoCrupier, Bot *arrayBots) {
    int i = 0;
    if (resultadoCrupier <= 21) {
        for (i = 0; i < returnNumBots(); i++) {
            if(teHasPasado(arrayBots[i].puntuacionCartasBot)==1){
                arrayBots[i].derrotas = arrayBots[i].derrotas + 1;
                printf("El bot %s pierde\n",  arrayBots[i].nombre);
            }else if (arrayBots[i].puedeGanar == 1 && arrayBots[i].puntuacionCartasBot > resultadoCrupier) {
                arrayBots[i].victorias = arrayBots[i].victorias + 1;
                arrayBots[i].fichas = arrayBots[i].fichas + (arrayBots[i].apuestaBot * 2);
                printf("El bot %s ha ganado esta ronda\n",  arrayBots[i].nombre);
            }else if (arrayBots[i].puedeGanar == 1 && arrayBots[i].puntuacionCartasBot == resultadoCrupier) {
                arrayBots[i].empates = arrayBots[i].empates + 1;
                arrayBots[i].fichas = arrayBots[i].fichas + (arrayBots[i].apuestaBot);
                printf("El bot %s empata con el crupier\n",  arrayBots[i].nombre);
            } else if (arrayBots[i].puedeGanar == 1 && arrayBots[i].puntuacionCartasBot < resultadoCrupier){
                arrayBots[i].derrotas = arrayBots[i].derrotas + 1;
                printf("El bot %s pierde\n",  arrayBots[i].nombre);
            }
        }
    } else if(resultadoCrupier>21){
        for (i = 0; i < returnNumBots(); i++) {
            if (arrayBots[i].puntuacionCartasBot<=21) {
                arrayBots[i].victorias = arrayBots[i].victorias + 1;
                arrayBots[i].fichas = arrayBots[i].fichas + (arrayBots[i].apuestaBot * 2);
                printf("\nEl bot %s ha ganado esta ronda\n",  arrayBots[i].nombre);
            } else{
                arrayBots[i].derrotas = arrayBots[i].derrotas + 1;
                printf("\nEl bot %s ha perdido esta ronda\n",  arrayBots[i].nombre);
            }
        }
    }
}

void ficherobot(Bot *arrayBots){

    Bot b;
    char nombre[50];
    int numfichas = 0;
    char caracter[50];
    int cartamax = 0;
    char aux[5];
    int  i;
    int j=0;
    int n;
    int numeroBots=0;


    FILE *fi=fopen("bots.txt","r");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fscanf(fi, "%i", &numeroBots);
        //arrayBots= (Bot*)malloc(sizeof(Bot)*numeroBots);
        fscanf(fi, "%c", &aux[0]);

        for (i =0; i<=numeroBots; i++){
            while (!feof(fi)) {

                fgets(nombre, 50, fi);
                n = strlen(nombre);
                nombre[n-1] = '\0';
                fscanf(fi, "%d", &numfichas);
                fscanf(fi, "%c", &aux[0]);
                fgets(caracter, 50, fi);
                n = strlen(caracter);
                caracter[n-1] = '\0';
                fscanf(fi, "%d", &cartamax);
                fscanf(fi, "%c", &aux[0]);

                strcpy(arrayBots[j].nombre, nombre);
                strcpy(arrayBots[j].caracter, caracter);
                arrayBots[j].fichas=numfichas;
                arrayBots[j].cartaMaxima=cartamax;
                arrayBots[j].puedeGanar=1;
                arrayBots[j].victorias=0;
                arrayBots[j].empates=0;
                arrayBots[j].derrotas=0;
                j++;
            }
        }


        fclose(fi);
    }

}

void estadisticasBot(Bot *arrayBots){
    int i=0;
    for(i=0;i<returnNumBots();i++){
        printf("\nEl bot %s tiene %i partidas ganadas (%.2f %%), %i empates (%.2f %%) y %i derrotas (%.2f %%) y le quedan %i fichas",
               arrayBots[i].nombre,
               arrayBots[i].victorias,
               (float)arrayBots[i].victorias/(arrayBots[i].victorias+arrayBots[i].empates+arrayBots[i].derrotas)*100,
               arrayBots[i].empates,
               (float)arrayBots[i].empates/(arrayBots[i].victorias+arrayBots[i].empates+arrayBots[i].derrotas)*100,
               arrayBots[i].derrotas,
               (float)arrayBots[i].derrotas/(arrayBots[i].victorias+arrayBots[i].empates+arrayBots[i].derrotas)*100,
               arrayBots[i].fichas);
    }

}


int returnNumBots(){

    int numeroBots=0;


    FILE *fi=fopen("bots.txt","r");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fscanf(fi, "%i", &numeroBots);
        fclose(fi);
    }

    return numeroBots;

}






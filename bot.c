
#include <stdio.h>
#include <string.h>
#include "bot.h"
#include "mesa.h"
#include "comprobaciones.h"


void muestraCartasBots(int numBots, Bot *arrayBots){

    int i=0;
    int ii=0;

    for(i=0; i<numBots;i++){
        printf("\nEl bot %s tiene en la mano, %13i fichas apostadas \n",arrayBots[i].nombre, arrayBots[i].apuestaBot);
        for(ii=0;ii<10;ii++){
            if(arrayBots[i].manobot[ii]>0 && arrayBots[i].manobot[ii]<22)
            printf("[%i]", arrayBots[i].manobot[ii]);
        }
        printf("\tpuntuacion de las cartas: %i", arrayBots[i].puntuacionCartasBot);
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
    int ultimaCarta=0;
    int turnoBot=0;
    for (i = 0; i <returnNumBots() ; i++) {
        if (retornaApuesta(arrayBots[i])==0){
            printf("\nEl bot %s no puede apostar", arrayBots[i].nombre);
            arrayBots[i].noApuesta=1;
        } else{
            arrayBots[i].noApuesta=0;
            arrayBots[i].apuestaBot=retornaApuesta(arrayBots[i]);
            arrayBots[i].fichas= arrayBots[i].fichas-arrayBots[i].apuestaBot;
            //printf("\nEl bot %s apuesta: %i", arrayBots[i].nombre, arrayBots[i].apuestaBot);
        }
    }

    for (i=0;i<returnNumBots();i++){
        if(arrayBots[i].noApuesta==0) {
            arrayBots[i].puntuacionCartasBot = 0;
            for (ii = 0; ii < 2; ii++) {
                arrayBots[i].manobot[ii] = dameCarta(c);
                arrayBots[i].puntuacionCartasBot = arrayBots[i].puntuacionCartasBot + arrayBots[i].manobot[ii];
            }

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
                        i++;
                        turnoBot++;
                    }

                } else {
                    if (teHasPasado(arrayBots[i].puntuacionCartasBot) == 1) {
                        arrayBots[i].puedeGanar = 1;
                    }
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
    float victorias, derrotas, empates;

    printf("Nombre            Fichas         P.Ganadas       P.Empatadas      P.Perdidas\n");
    printf("----------------------------------------------------------------------------\n");

    for(i=0;i<returnNumBots();i++){

        victorias = (float)arrayBots[i].victorias/(arrayBots[i].victorias+arrayBots[i].empates+arrayBots[i].derrotas)*100,

              empates = (float)arrayBots[i].empates/(arrayBots[i].victorias+arrayBots[i].empates+arrayBots[i].derrotas)*100,

              derrotas =  (float)arrayBots[i].derrotas/(arrayBots[i].victorias+arrayBots[i].empates+arrayBots[i].derrotas)*100,



        printf("%-18s", arrayBots[i].nombre);
        printf("%6d", arrayBots[i].fichas);
        printf("%10d",  arrayBots[i].victorias);
        printf(" (%.1f%%)",  victorias);

       printf("%10d", arrayBots[i].empates);
        printf(" (%.1f%%)", empates);

        printf("%8d", arrayBots[i].derrotas);
        printf(" (%.1f%%)\n", derrotas);
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









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
    if(resultadoCrupier>21){
        c.vecesMayor21=c.vecesMayor21+1;
    }
    ficheroCrupier(c);
    return c;

}

void ficheroCrupier (Crupier crupier) {

    FILE *fiche;
    fiche = fopen("estadisticaCrupier.txt", "w");
    if (fiche == NULL) {
        printf("ERROR.");
    } else {
        fprintf(fiche, "%i", crupier.veces17);
        fprintf(fiche, "\n%i", crupier.veces18);
        fprintf(fiche, "\n%i", crupier.veces19);
        fprintf(fiche, "\n%i", crupier.veces20);
        fprintf(fiche, "\n%i", crupier.veces21);
        fprintf(fiche, "\n%i", crupier.vecesMayor21);

    }

    fclose(fiche);

}



    void estadisticasCrupier(Crupier *crupier) {

        FILE *fich;
        char aux[10];

        fich = fopen("estadisticaCrupier.txt", "r");
        if (fich == NULL) {
            printf("ERROR.");
        } else {

            fscanf(fich, "%i", &crupier->veces17);
            fscanf(fich, "%c", &aux[0]);
            fscanf(fich, "%i", &crupier->veces18);
            fscanf(fich, "%c", &aux[0]);
            fscanf(fich, "%i", &crupier->veces19);
            fscanf(fich, "%c", &aux[0]);
            fscanf(fich, "%i", &crupier->veces20);
            fscanf(fich, "%c", &aux[0]);
            fscanf(fich, "%i", &crupier->veces21);
            fscanf(fich, "%c", &aux[0]);
            fscanf(fich, "%i", &crupier->vecesMayor21);

        }

        printf("igual 17:%i\n", crupier->veces17);
        printf("igual 18:%i\n", crupier->veces18);
        printf("igual 19:%i\n", crupier->veces19);
        printf("igual 20:%i\n", crupier->veces20);
        printf("igual 21:%i\n", crupier->veces21);
        printf("mayor 21:%i\n", crupier->vecesMayor21);

        fclose(fich);

    }



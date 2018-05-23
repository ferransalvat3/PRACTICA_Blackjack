//
// Created by Ferran Salvat on 24/5/18.
//

#include "ficheros.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
void ficherobot(){

    Bot b;
    char nombre[50];
    int numbots = 0;
    int numfichas = 0;
    char caracter[50];
    int cartamax = 0;
    char aux[5];
    int  i;


    FILE *fi=fopen("bots.txt","r");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fscanf(fi, "%d", &numbots);
        printf("Num.Bots: %d\n", numbots);
        fgets(b.nombre, 50, fi);

        for (i =0; i<=numbots; i++){
            while (!feof(fi)) {

                fgets(b.nombre, 50, fi);

                fscanf(fi, "%d", &b.fichas);
                fscanf(fi, "%c", &aux[0]);
                fgets(b.caracter, 50, fi);
                fscanf(fi, "%d", &b.cartaMaxima);
                fscanf(fi, "%c", &aux[0]);


                printf("Nombre:%s\n", b.nombre);
                printf("Fichas:%d\n", b.fichas);
                printf("Caracter: %s\n", b.caracter);
                printf("Carta Maxima: %d\n", b.cartaMaxima);

            }
        }

        fclose(fi);
    }
}


void ficherojugador(){

    char nombre[50];
    int numfichas = 0;
    int numganadas = 0;
    int numperdidas = 0;
    int numempatadas = 0;
    char aux[5];

    FILE *fi=fopen("jugador.txt","rw");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fgets(nombre, 50, fi);
        while (!feof(fi)) {
            fscanf(fi, "%d", &numfichas);
            fscanf(fi, "%c", &aux[0]);
            fscanf(fi, "%d", &numganadas);
            fscanf(fi, "%c", &aux[0]);
            fscanf(fi, "%d", &numperdidas);
            fscanf(fi, "%c", &aux[0]);
            fscanf(fi, "%d", &numempatadas);
            fscanf(fi, "%c", &aux[0]);

            fgets(nombre, 50, fi);

        }

        printf("Nombre:%s\n", nombre);
        printf("Fichas:%d\n", numfichas);
        printf("Manos_ganadas: %d\n", numganadas);
        printf("Manos_perdidas: %d\n", numperdidas);
        printf("Manos_empatadas: %d\n", numempatadas);

        fclose(fi);
    }
}

*/

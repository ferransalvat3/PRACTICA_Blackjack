#include <stdio.h>
#include <mem.h>
#include "jugador.h"


int retornaPartidasGanadas(Jugador j){
    return j.manos_ganadas;
}

int compruebaFichasJugador(Jugador j, int fichas){
    if(j.fichas>=fichas){
        return 1;
    } else{
        return 0;
    }
}

int retornaFichasJugador(Jugador j){
    return j.fichas;
}

Jugador ficherojugador(){

    FILE *fi;
    char nombre[50];
    int numfichas = 0;
    int numganadas = 0;
    int numperdidas = 0;
    int numempatadas = 0;
    char aux[5];
    Jugador j;

    fi = fopen("jugador.txt","rw");
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
    strcpy(j.nombre, nombre);
    j.fichas = numfichas;
    j.manos_ganadas=numganadas;
    j.manos_perdidas=numperdidas;
    j.manos_empatadas=numempatadas;

    return j;
}
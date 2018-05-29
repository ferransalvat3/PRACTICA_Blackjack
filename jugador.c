#include <stdio.h>
#include <string.h>
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

Jugador ficherojugador(Jugador j){

    FILE *fi;
    char nombre[50];
    int numfichas = 0;
    int numganadas = 0;
    int numperdidas = 0;
    int numempatadas = 0;
    char aux[5];
    int n;
    int i;
    int totalpartidas = j.manos_ganadas+j.manos_perdidas+j.manos_empatadas;
    //Jugador j;

    fi = fopen("jugador.txt","rw");
    if (fi==NULL){
        printf("ERROR.");
    }else{
        fgets(nombre, 50, fi);
        n = strlen(nombre);
        nombre[n-1] = '\0';
        while (!feof(fi)) {
            fscanf(fi, "%i", &numfichas);
            fscanf(fi, "%c", &aux[0]);
            fscanf(fi, "%i", &numganadas);
            fscanf(fi, "%c", &aux[0]);
            fscanf(fi, "%i", &numperdidas);
            fscanf(fi, "%c", &aux[0]);
            fscanf(fi, "%i", &numempatadas);
            fscanf(fi, "%c", &aux[0]);

            fgets(nombre, 50, fi);

            strcpy(j.nombre, nombre);
            j.fichas = numfichas;
            j.manos_ganadas=numganadas;
            j.manos_perdidas=numperdidas;
            j.manos_empatadas=numempatadas;

            fprintf(fi, "manos_ganadas: %i", j.manos_ganadas);
            fprintf(fi, "manos_perdidas: %i", j.manos_perdidas);
            fprintf(fi, "manos:empatadas: %i", j.manos_empatadas);

            for(i=0; i<totalpartidas; i++){
                fprintf(fi, "fichas_partida_%i", j.fichas);
            }

        }

    /*
        printf("\nNombre:%s\n", nombre);
        printf("Fichas:%d\n", numfichas);
        printf("Manos_ganadas: %d\n", numganadas);
        printf("Manos_perdidas: %d\n", numperdidas);
        printf("Manos_empatadas: %d\n", numempatadas);

    */
        fclose(fi);

    }



    return j;
}


void estadisticasJugador(Jugador j){

    int totalpartides =  0;
    totalpartides = j.manos_ganadas+j.manos_perdidas+j.manos_empatadas;


    printf("\nEl jugador %s tiene %i partidas ganadas (%f %%), %i empates (%f %%) y %i derrotas (%f %%) y le quedan %i fichas",
           j.nombre,
           j.manos_ganadas,
           (float)j.manos_ganadas/(totalpartides*100),
           j.manos_empatadas,
           (float)j.manos_empatadas/(totalpartides*100),
           j.manos_perdidas,
           (float)j.manos_perdidas/(totalpartides*100),
           j.fichas);

}



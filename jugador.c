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
    int totalpartidas;
    

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

            strcpy(j.nombre, nombre);
            j.fichas = numfichas;
            j.manos_ganadas=numganadas;
            j.manos_perdidas=numperdidas;
            j.manos_empatadas=numempatadas;

        }
        fclose(fi);

    }



    return j;
}


void estadisticasJugador(Jugador *j) {

    int totalpartides = 0;
    //totalpartides = j->manos_ganadas + j->manos_perdidas + j->manos_empatadas;
    float ganadas = 0.0;
    float empatadas = 0.0;
    float perdidas = 0.0;
    FILE *fichero;
    char aux[5];

    fichero = fopen("estadisticaJugador.txt", "r");
    if (fichero == NULL) {
        printf("ERROR.");
    } else {

        fscanf(fichero, "%i", &j->manos_ganadas);
        fscanf(fichero, "%c", &aux[0]);
        fscanf(fichero, "%i", &j->manos_empatadas);
        fscanf(fichero, "%c", &aux[0]);
        fscanf(fichero, "%i", &j->manos_perdidas);

        totalpartides = j->manos_ganadas + j->manos_perdidas + j->manos_empatadas;
        ganadas = ((float)j->manos_ganadas / totalpartides) * 100;
        empatadas = ((float)j->manos_empatadas / totalpartides) * 100;
        perdidas = ((float)j->manos_perdidas / totalpartides )* 100;

    }
    printf("Partidas ganadas: %d (%.1f%%)\n", j->manos_ganadas, ganadas);
    printf("Partidas empatadas: %d (%.1f%%)\n", j->manos_empatadas, empatadas);
    printf("Partidas perdidas: %d (%.1f%%)\n\n", j->manos_perdidas, perdidas);

    fclose(fichero);

}

void escribirFichero (Jugador j){

    FILE *fic;
    fic = fopen("estadisticaJugador.txt","w");
    if (fic==NULL){
        printf("ERROR.");
    }else {
        fprintf(fic,"\n%i", j.manos_ganadas);
        fprintf(fic,"\n%i", j.manos_empatadas);
        fprintf(fic,"\n%i", j.manos_perdidas);
    }
    fclose(fic);
}


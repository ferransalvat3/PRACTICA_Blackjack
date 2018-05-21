//
// Created by Ferran Salvat on 16/5/18.
//

#include "menu.h"
#include <stdio.h>
#include "barajas.h"


int  menuPrincipal() {

    int opcion = 0;

    while(opcion <= 4)
    {
        printf("BLACKJACK\n");
        printf("1- Generar pila cartas.\n");
        printf("2- Jugar.\n");
        printf("3- Mostrar estadisticas.\n");
        printf("4- Salir.\n");


        printf("Opcion: _\n");
        scanf("%d", &opcion);

        if (opcion > 4){
            printf("Opcio incorrecte, vuelve a introducir una opcion (1-4):\n");
        }else{
            switch(opcion){
                case 1:
                    //barallaCrea(int numbaralles);
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;

            }

        }
    }
    return opcion;
}

int menuJugar() {
    int option = 0;

    while(option <= 4)
    {
        printf("Que quieres hacer?\n");
        printf("1- Perdir cartas.\n");
        printf("2- Plantarse.\n");
        printf("3- Rendirse.\n");
        printf("4- Abandonar partida.\n");


        printf("Opcion: _\n");
        scanf("%d", &option);

        if (option > 4){
            printf("Opcio incorrecte, vuelve a introducir una opcion (1-4)\n");
        }else{
            switch(option){
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;

            }

        }
    }
    return option;
}

int menuEstadistica(){

    int opcio = 0;

    while(opcio <= 4)
    {
        printf("Elige el tipo de estadísticas a visualizar:\n");
        printf("1- Jugador.\n");
        printf("2- Bots.\n");
        printf("3- Crupier.\n");
        printf("4- Regresar al menú principal.\n");


        printf("Opcion: _\n");
        scanf("%d", &opcio);

        if (opcio > 4){
            printf("Opcio incorrecte, vuelve a introducir una opcion (1-4):\n");
        }else{
            switch(opcio){
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:
                    menuPrincipal();
                    break;

            }

        }
    }
    return opcio;

}



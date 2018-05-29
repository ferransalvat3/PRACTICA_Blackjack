//
// Created by Ferran Salvat on 16/5/18.
//

#include "menu.h"
#include "bot.h"
#include "jugador.h"
#include "partida.h"
#include <stdio.h>



int  menuPrincipal(int opcion) {

    Baralles c;
    Jugador j;

    int numbaralles = 0;



    while(opcion <=3 )
        {
            printf("\nBLACKJACK\n");
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
                        printf("Indica el numero de barajas:\n");
                        scanf("%d", &numbaralles);

                        while (numbaralles<1 || numbaralles>4){
                            printf("No se pueden crear tantas barajas(1-4). Introduce un numero valido.\n");
                            scanf("%d", &numbaralles);
                        }
                        if (numbaralles>1 || numbaralles<4 ){
                            printf("La baralla se ha creado correctamente\n");
                        }
                            barallaCrea(numbaralles);
                        break;


                    case 2:
                        //menuJugar(opcion);
                        ficherobot();
                        j=ficherojugador(j);


                            while (1) {
                                c = barallaCrea(numbaralles);
                                partida(c, j);
                                menuPrincipal(opcion);
                                break;
                                //estadisticasBot();
                                // estadisticasJugador();
                            }

                        break;


                    case 3:
                        menuEstadistica(opcion,j);
                        break;

                    case 4:
                        break;



                }

            }
    }
    return opcion;
}



int menuEstadistica(int opcion, Jugador j){


    while(opcion < 4)
    {
        printf("\nElige el tipo de estadísticas a visualizar:\n");
        printf("1- Jugador.\n");
        printf("2- Bots.\n");
        printf("3- Crupier.\n");
        printf("4- Regresar al menú principal.\n");


        printf("Opcion: _\n");
        scanf("%d", &opcion);

        if (opcion > 4){
            printf("Opcio incorrecte, vuelve a introducir una opcion (1-4):\n");
        }else{
            switch(opcion){
                case 1:
                    estadisticasJugador(j);
                    break;
                case 2:
                    estadisticasBot();
                    break;
                case 3:
                    printf("No hemos podido implementar esta funcion..\n");
                    break;
                case 4:
                    menuPrincipal(opcion);
                    break;

            }

        }
    }
    return opcion;

}



//
// Created by smoreno on 02/05/2018.
//

int teHasPasado(int valor){
    if (valor>21){
        return 1;
    } else{
        return 0;
    }
}

int compruebaBlackJack(int valor){
    if (valor == 21){
        return 1;
    } else{
        return 0;
    }

}

int compruebaManos(int resultadoJugador, int resultadoCroupier){
    if(resultadoCroupier > resultadoJugador){
        return 1;
    } else if( resultadoJugador > resultadoCroupier){
        return 2;
    } else{
        return 3;
    }
}
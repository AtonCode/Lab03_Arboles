#include<iostream>
#include <stdio.h>
#include <iterator>
#include "TadsArboles/ArbolBinario.h"
#include "Jugador.h"


int main(){

    // Crear arbol para n participantes
    int numeroJugadores = 7;
    ArbolBinario<Jugador> arbolBinarioJugadores;
    Jugador jugador1
    Jugador jugador2
    Jugador jugador3 
    Jugador jugador4
    Jugador jugador5
    Jugador jugador6
    Jugador jugadorGanador;

    // Crear Arbol jugadores noName
    arbolBinarioJugadores(jugadorGanador);
    for(int i = 0; i < numeroJugadores; i++){
        Jugador jugador;
        arbolBinarioJugadores.insertar(jugador, jugador);
    }

    //Modificar ultimo nivel del arbol -> Recorrer por niveles y editar
    jugador1.name = "Andres"
    jugador1.points = 1;
    jugador1.state = true;

    jugador2.name = "Juan"
    jugador2.points = 1;
    jugador2.state = true;

    jugador3.name = "Baki"
    jugador3.points = 1;
    jugador3.state = true;

    jugador4.name = "Santiago"
    jugador4.points = 1;
    jugador4.state = true;

    jugador5.name = "Luis"
    jugador5.points = 1;
    jugador5.state = true;

    jugador6.name = "Jose"
    jugador6.points = 1;
    jugador6.state = true;

    //Modificar el Ultimo nivel para cargar los jugadores

    //Imprimir arbol por niveles
    arbolBinarioJugadores.nivelOrden(arbolBinarioJugadores.obtenerRaiz());
    
    //Iniciar Juego eliminando si el jugador es noName o tiene un menor puntaje
    arbolBinarioJugadores.eliminar(jugador2);
    



}
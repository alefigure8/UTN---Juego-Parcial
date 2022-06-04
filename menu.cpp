#include <Windows.h>
#include <iostream>
#include<locale>
#include <iomanip>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
using namespace std;

/* Funciones */
void menuInicial();
Jugadores pedir_nombre(int x);
void quienEmpieza(Jugadores *jugador, string &jugadorActual);

enum OPCIONES {
  SALIR = 0,
  INICIAR_JUEGO = 1,
  ESTADISTICAS = 2,
  CREDITOS = 3
};

/* Main */
int main (void){
  setlocale(LC_ALL, "spanish"); // Para que se vea correctamente el texto en la consola
  ResizeConsole(850,550); // Cambiar tamaùo de consola
  menuInicial(); // Menu inicial

  return 0;
}

/* Funcion para el munnu de inicio */
void menuInicial(){
  Jugadores jugadores[2];
  string jugadorActual;
  int eleccion;

  do{
    lines(2);
    colorTexto(15);
    imprimir_titulo();
    endLines(3);
    colorTexto(10); cout << endl << setw(40 + 11) << "(1) - JUGAR";
    colorTexto(14); cout << endl << setw(40 + 17)<< "(2) - ESTADISTICA";
    colorTexto(14); cout << endl << setw(40 + 14)<< "(3) - CERDITOS";
    endLines(1);
    colorTexto(12); cout << endl << setw(40 + 11)<< "(0) - SALIR";
    endLines(3);
    colorTexto(9); cout << endl << setw(80)<< "V1.0.0";
    endLines(3);
    lines(2);

    cin >>  eleccion;

    switch (eleccion){
    case OPCIONES::INICIAR_JUEGO: {
      for (int i = 0; i < 2; i++)
      {
        jugadores[i] = pedir_nombre(i);
      }
      quienEmpieza(jugadores, jugadorActual);
    }
      break;
    }
  }while(eleccion != OPCIONES::SALIR);

}

/* Funcion que pide los nombres de los jugadores*/
 Jugadores pedir_nombre(int x){

   Jugadores jugadores;

    string dialog = "";

    // segun el turno cambia el dialogo
    if(x == 0){
      dialog = "øCu·l es tu nombre, cerdo uno?";
    } else {
      dialog =  "Tu turno, cerdo dos, øcu·l es tu nombre?";
    }

    lines(1);
    endLines(6);
    cerdo(x, dialog); // Imprime cerdo
    endLines(8);
    lines(2);

    colorTexto(15);
    cin >> jugadores.jugador;
    jugadores.puntaje = 0;

    return jugadores;
 }



/* Funcion que aùade el decorado de lineas a cada pantalla*/
 void lines(int x){
   cout << endl;
      for (int i = 0; i < 98; i++)
    {
      colorTexto(2); cout << "#";
    }
    cout << endl;
   if(x == 1){
      colorTexto(15); cout << "THE KING OF PIGS" << endl;
   }
 }


/* Funcion para determinar cual jugador comienza*/
void quienEmpieza(Jugadores *jugador, string &jugadorActual){
  int CANT_DADOS = 2;
  int CANT_JUGADORES = 2;
  int dados_jugadores[3];
  int totalJugadores[2][3];
  int sumaMaxima = 0;
  int jugadorSumaMaxima;
  int dadoMaximo = 0;
  int jugadorDadoMaximo;
  int totalJugador1= totalJugadores[0][0] + totalJugadores[0][1];
  int totalJugador2= totalJugadores[1][0] + totalJugadores[1][1];
  string dialog;

  iniciarMatriz(totalJugadores, CANT_JUGADORES, CANT_DADOS);

  char eleccion;

  for (int i = 0; i < CANT_JUGADORES; i++){
    /* Pantalla 1*/
    lines(1);
    endLines(8);
    if(i == 0){
      dialog = "Lanza los dados, " + jugador[i].jugador +  " øEst·s listos? (S/N)";
    } else {
      dialog = "Ahora es tu turno " + jugador[i].jugador  +  " øEst·s listos? (S/N)";
    }

    cerdo2(i, dialog);

    endLines(8);
    lines(2);

    cin >> eleccion;

    /* Pantalla 2*/
    lines(1);
    endLines(8);
  
    if(eleccion == 'S'){

      dados(dados_jugadores, 2);

      for (int j = 0; j < CANT_DADOS; j++){
        totalJugadores[i][j] += dados_jugadores[j];
        imprimirDados(dados_jugadores[j]);
      }
    } else {
      if(i == 0){ // Si no quiere tirar, cede turno
       jugadorActual = jugador[1].jugador ;
       i = 2;
      } else {
        jugadorActual = jugador[0].jugador;
        i = 2;
      }
    }

    int total = 0;

    for (int j = 0; j < CANT_DADOS; j++){
      total += totalJugadores[i][j];

      if(totalJugadores[i][j] > dadoMaximo){
        dadoMaximo = totalJugadores[i][j];
        jugadorDadoMaximo = i + 1;
      }
    }

    string strTotal = to_string(total);
    colorTexto(15);cout << setw(50) <<"Has sumado " + strTotal + "!";

    endLines(8);
    lines(2);
    rlutil::anykey();

    /* Guarda el maximo puntaje */
    if(total > sumaMaxima){
      sumaMaxima = total;
      jugadorSumaMaxima = i + 1;
    }

    /* Asigna turno dependiendo el puntaje*/
    if(totalJugador1 != totalJugador2){
        if (jugadorSumaMaxima == 1){ // si no hay empate
        jugadorActual = jugador[0].jugador;
      } else {
        jugadorActual = jugador[1].jugador;
      }
    } else {
      if (jugadorDadoMaximo == 1){ // si hay empate
        jugadorActual = jugador[0].jugador;
      } else {
        jugadorActual = jugador[1].jugador;
      }
    }
  }

  lines(1);
  endLines(8);

  dialog = "°COMIENZA EL JUGADOR " + jugadorActual + "!";
  cerdo2(0, dialog);

  endLines(8);
  lines(2);

  rlutil::anykey();
}


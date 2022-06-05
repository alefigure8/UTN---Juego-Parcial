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
  ResizeConsole(850,550); // Cambiar tamano de consola
  menuInicial(); // Menu inicial

  return 0;
}

/* Funcion para el munnu de inicio */
void menuInicial(){
  Jugadores jugadores[2]; // Inicializar Struct de Jugadores
  string jugadorActual;
  int eleccion;

  do{

    // TODO PASAR ESTO A UNA PANTALLA
    system("cls"); // Limpiar pantalla
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

/* Funcion para determinar cual jugador comienza*/
void quienEmpieza(Jugadores *jugador, string &jugadorActual){
  int CANT_DADOS = 2;
  int CANT_JUGADORES = 2;

  int sumaMaxima = 0;
  int jugadorSumaMaxima;
  int dadoMaximo = 0;
  int jugadorDadoMaximo;

  string dialog;

  for (int i = 0; i < CANT_JUGADORES; i++){
    if(i == 0){
      dialog = "Lanza los dados, " + jugador[i].jugador +  " �Est�s listos?";
    } else {
      dialog = "Ahora es tu turno " + jugador[i].jugador  +  " �Est�s listos?";
    }
    /* Pantalla 1*/
    pantalla_generica(i, 2, dialog);


    // TODO hacer una pantalla generica para los dados
    /* Pantalla 2*/
    system("cls"); // Limpiar pantalla
    lines(1);
    endLines(8);
  
    dados(jugador[i].dados_jugadores, CANT_DADOS); // generamos numeros random
    jugador[i].suma_dados = sumar_dados(jugador[i].dados_jugadores, CANT_DADOS); // summamos los dados

    for (int j = 0; j < CANT_DADOS; j++){
      imprimirDados(jugador[i].dados_jugadores[j]); // imprimimos los dados
    }

    for (int j = 0; j < CANT_DADOS; j++){ // buscamos el dado con mayor valor
      obtener_maximo(jugador[i].dados_jugadores[j], dadoMaximo, i, jugadorDadoMaximo);
    }

    string strTotal = to_string(jugador[i].suma_dados); // convertimos a string
    colorTexto(15); cout << setw(50) <<"Has sumado " + strTotal + "!"; // imprimimos la suma

    endLines(8);
    lines(2);
    rlutil::anykey();

    obtener_maximo(jugador[i].suma_dados, sumaMaxima, i, jugadorSumaMaxima); // buscamos el jugador con mayor suma

    //TODO pasar esto a una funcion
    if(jugador[0].suma_dados != jugador[1].suma_dados){ // si no hay empate
        if (jugadorSumaMaxima == 1){
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

  dialog = "�COMIENZA EL JUGADOR " + jugadorActual + "!" ;
  /* Pantalla 3*/
  pantalla_generica(0, 1, dialog);
}


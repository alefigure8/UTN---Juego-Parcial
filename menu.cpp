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
#include "headers/juego.h"
#include "headers/menu.h"
using namespace std;

void quienEmpieza(Jugadores *jugador, int &jugadorActual);
void obtener_quien_empieza(Jugadores *jugador, int &jugadorActual, int &jugadorDadoMaximo, int &jugadorSumaMaxima);

enum OPCIONES {
  SALIR = 0,
  INICIAR_JUEGO = 1,
  ESTADISTICAS = 2,
  CREDITOS = 3
};


/* Funcion para el munnu de inicio */
void menuInicial(){
  Jugadores jugadores[2]; // Inicializar Struct de Jugadores
  int jugadorActual;
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
      comenzar_juego(jugadores, jugadorActual);
    }
      break;
    }
  }while(eleccion != OPCIONES::SALIR);

}

// TODO averiguar como hacer para pasar por parametro una estructura
/* Funcion para determinar cual jugador comienza*/
void quienEmpieza(Jugadores *jugador, int &jugadorActual){
  int CANT_DADOS = 2;
  int CANT_JUGADORES = 2;

  int sumaMaxima = 0;
  int jugadorSumaMaxima;
  int dadoMaximo = 0;
  int jugadorDadoMaximo;

  string dialog;

  for (int i = 0; i < CANT_JUGADORES; i++){

    if(i == 0){
      dialog = "Lanza los dados, ";
    } else {
      dialog = "Ahora es tu turno ";
    }

    // Pantalla 1
    pantalla_generica(i, 2, dialog, jugador[i].jugador); 

    // generamos numeros random
    dados(jugador[i].dados_jugadores, CANT_DADOS);
    jugador[i].suma_dados = sumar_dados(jugador[i].dados_jugadores, CANT_DADOS);

    // Imprimimos los dados
    string resultado_imprimir_dado;
    for (int j = 0; j < CANT_DADOS; j++){
      resultado_imprimir_dado += imprimirDados(jugador[i].dados_jugadores[j]);
    }

    // buscamos el dado con mayor valor
    for (int j = 0; j < CANT_DADOS; j++){ 
      obtener_maximo(jugador[i].dados_jugadores[j], dadoMaximo, i, jugadorDadoMaximo);
    }

    // convertimos a string
    string strTotal = to_string(jugador[i].suma_dados);
    dialog = "Has sumado " + strTotal + ", " + jugador[i].jugador + "!";

    // Pantalla 2
    pantalla_generica_2(i, resultado_imprimir_dado, dialog, jugador[0].jugador, jugador[1].jugador ,jugador[0].suma_dados, jugador[1].suma_dados); 

    // buscamos el jugador con mayor suma
    obtener_maximo(jugador[i].suma_dados, sumaMaxima, i, jugadorSumaMaxima); 

    // buscamos el jugador con mayor suma o dado
    obtener_quien_empieza(jugador, jugadorActual, jugadorDadoMaximo, jugadorSumaMaxima); 
  }

  dialog = "COMIENZA A JUGAR " ;
  pantalla_generica(0, 2, dialog, jugador[jugadorActual].jugador); // Pantalla 3
}

// TODO averiguar como hacer para pasar por parametro una estructura
/* Funcion que determina cual jugador empieza */
void obtener_quien_empieza(Jugadores *jugador, int &jugadorActual, int &jugadorDadoMaximo, int &jugadorSumaMaxima){
   if(jugador[0].suma_dados != jugador[1].suma_dados){ // si no hay empate
        if (jugadorSumaMaxima == 1){
        jugadorActual = 0;
      } else {
        jugadorActual = 1;
      }
    } else {
      if (jugadorDadoMaximo == 1){ // si hay empate
        jugadorActual = 0;
      } else {
        jugadorActual = 1;
      }
    }
} 
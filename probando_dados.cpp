#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "headers/rlutil.h"

using namespace std;
void pantalla_puntaje();
void pdv_lanzamientos(int a, int b, int & lanzamientos_jugador_1, int & lanzamientos_jugador_2);
void pdv_oink(int a, int b, int & oinks_jugador_1, int & oinks_jugador_2);
int pdv_cada_50_trufas(int a);
void pdv_trufas_total(int a, int b, int &a_1, int &b_2);

int main(){
  system("cls");

  pantalla_puntaje();

  return 1;
}

// Mostrar el puntaje final
void pantalla_puntaje(){
  string eleccion;
  int pdv_trufas_jugador_1 = 0;
  int pdv_trufas_jugador_2 = 0;
  int pdv_oinks_jugador_1 = 0;
  int pdv_oinks_jugador_2 = 0;
  int pdv_lanzamientos_jugador_1 = 0;
  int pdv_lanzamientos_jugador_2 = 0;
  int pdv_50_trufas_jugador_1 = pdv_cada_50_trufas(59);
  int pdv_50_trufas_jugador_2 = pdv_cada_50_trufas(68);
  int COLUMNA = 5;
  int FILA = 8;
  int FILA_JUGADOR_1 = 40;
  int FILA_JUGADOR_2 = 75;

  // Calculamos los puntos de vida
  pdv_trufas_total(59, 68, pdv_trufas_jugador_1, pdv_trufas_jugador_2);
  pdv_oink(5, 7, pdv_oinks_jugador_1, pdv_oinks_jugador_2);
  pdv_lanzamientos(5, 3, pdv_lanzamientos_jugador_1, pdv_lanzamientos_jugador_2);

  int total_jugador_1 = pdv_trufas_jugador_1 + pdv_oinks_jugador_1 + pdv_lanzamientos_jugador_1 + pdv_50_trufas_jugador_1;
  int total_jugador_2 = pdv_trufas_jugador_2 + pdv_oinks_jugador_2 + pdv_lanzamientos_jugador_2 + pdv_50_trufas_jugador_2;

  do{
    rlutil::cls;
    //lines();
    // mostrar nombres
    rlutil::locate(FILA, 7); cout << "HITO";
    rlutil::locate(FILA_JUGADOR_1, 7); cout << "PEDRO";
    rlutil::locate(FILA_JUGADOR_2, 7); cout << "ALE";

    rlutil::locate(FILA, 8); cout << "-----------------------------------------------------------------------------------------";

    // mas trufas en total
    rlutil::locate(FILA, 10); cout << "Más trufas en total";
    rlutil::locate(FILA_JUGADOR_1, 10); cout << pdv_trufas_jugador_1 << " PDV (" << 59 << ")";
    rlutil::locate(FILA_JUGADOR_2, 10); cout << pdv_trufas_jugador_2 << " PDV (" << 68 << ")";

    // cada 50 puntos
     rlutil::locate(FILA, 12); cout << "Cada 50 Trufas";
     rlutil::locate(FILA_JUGADOR_1, 12); cout << pdv_50_trufas_jugador_1 << " PDV (" << 59 << ")";
     rlutil::locate(FILA_JUGADOR_2, 12); cout << pdv_50_trufas_jugador_2 << " PDV (" << 68 << ")";

    // oinks
    rlutil::locate(FILA, 14); cout << "Oinks";
    rlutil::locate(FILA_JUGADOR_1, 14); cout << pdv_oinks_jugador_1 << " PDV (" << 5  << " Oinks) ";
    rlutil::locate(FILA_JUGADOR_2, 14); cout << pdv_oinks_jugador_2 << " PDV (" << 7  << " Oinks) ";


    // lanzamientos
    rlutil::locate(FILA, 16); cout << "Cerdo codicioso";
    rlutil::locate(FILA_JUGADOR_1, 16); cout << pdv_lanzamientos_jugador_1 << " PDV ("<< 5 << " Lanzamientos) ";
    rlutil::locate(FILA_JUGADOR_2, 16); cout << pdv_lanzamientos_jugador_2 << " PDV ("<< 3 << " Lanzamientos) ";

    // total
    rlutil::locate(FILA, 17); cout << "-----------------------------------------------------------------------------------------";
    rlutil::locate(FILA, 19); cout << "TOTAL";
    rlutil::locate(FILA_JUGADOR_1, 19); cout << total_jugador_1 << " PDV";
    rlutil::locate(FILA_JUGADOR_2, 19); cout << total_jugador_2 << " PDV";

     rlutil::locate(FILA, 25); cout << "Ingrese Oink para continuar: " ;
     rlutil::locate(FILA, 26); cout << ">> ";
    rlutil::locate(FILA + 4, 26); cin >> eleccion;

  } while (eleccion != "oink" );

}

// Funcion otorga puntos de vida a partir de la cantidad de lanzamientos que realiza el jugador
void pdv_lanzamientos(int a, int b, int & lanzamientos_jugador_1, int & lanzamientos_jugador_2){
  if(a > b){
    lanzamientos_jugador_1 = 2;
  } else {
    lanzamientos_jugador_1 = 2;
  }
}


// Funcion otorga puntos de vida a partir de la cantidad de Oinks que realiza el jugador
void pdv_oink(int a, int b, int & oinks_jugador_1, int & oinks_jugador_2){
  oinks_jugador_1 = a * 2;
  oinks_jugador_2 = b * 2;
}


// Funcion que otorga puntos de vida cada 50 trufas
int pdv_cada_50_trufas(int a){
  int cada_50_puntos = a / 50;
  return cada_50_puntos * 5;
}


// Funcion que otorga puntos de vida al que mas puntos consiguio
void pdv_trufas_total(int a, int b, int &a_1, int &b_2){

  if(a > b){
    a_1 = 5;
  } else if(a < b){
    b_2 = 5;
  } else {
    a_1 = 5;
    b_2 = 5;
  }

}
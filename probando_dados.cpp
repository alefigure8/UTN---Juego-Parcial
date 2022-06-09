#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "headers/rlutil.h"
#include "headers/helpers.h"
#include "headers/graficas.h"

using namespace std;

void mostrar_reglas_prueba();

int main(){
  system("cls");
  mostrar_reglas_prueba();
 
  return 1;
}

void mostrar_reglas_prueba(){
  system("cls");
  lines();

  rlutil::locate(1, 28);
  cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;

  rlutil::locate(1, 4);
  cout << "REGLAS DEL JUEGO" << endl;

  endLines(2);
  cout << "1. El juego consiste en una serie de rondas, cada ronda tiene una cantidad de lanzamientos." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "2. Cada lanzamiento tiene una cantidad de trufas, cada trufa es una cantidad de puntos." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "3. El jugador que obtenga la mayor cantidad de puntos en todas las rondas gana el juego." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "4. El jugador que obtenga la mayor cantidad de puntos en una ronda gana la ronda." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "5. El jugador que obtenga la mayor cantidad de puntos en un lanzamiento gana el lanzamiento." << endl;
  rlutil::anykey();

}
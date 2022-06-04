#include <iostream>
#include <Windows.h>
#include <string>
#include <locale.h>
#include "headers/rlutil.h"
using namespace std;
struct Jugadores{
  string jugador[2];
  int puntaje[2];
  string jugadorActual;
} datos;

int main (){
  setlocale(LC_ALL, "Spanish");

  struct Jugadores jugadores;

  return 0;
}

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
#include "headers/menu.h"
using namespace std;

/* Main */
int main (void){
  setlocale(LC_ALL, "spanish"); // Para que se vea correctamente el texto en la consola
  ResizeConsole(850,550); // Cambiar tamano de consola
  menuInicial(); // Menu inicial

  return 0;
}
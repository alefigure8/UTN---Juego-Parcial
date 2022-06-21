#pragma once
#ifndef JUGADORES_H
#define JUGADORES_H
// #include <string>
// #include <iostream>
// #include <Windows.h>
// #include <algorithm>
// #include "graficas.h"
#include "../jugadores.cpp"
//using namespace std;

struct Jugadores;
Jugadores inicializar_estructura();
void pedir_nombre(Jugadores *jugadores);
void continuar_jugando(Jugadores &jugadores);

#endif // JUGADORES_H

#pragma once
#ifndef HELPERS_H
#define HELPERS_H

#include <Windows.h>
#include <iostream>
#include <string>
#include "../helpers.cpp"
#include "jugadores.h"
using namespace std;

void ResizeConsole(int width, int height);
void colorTexto (int x);
void endLines(int x);
void iniciar_vector(int *vector, int filas);
void obtener_maximo(int total, int &maximo, int i, int &jugadorMaximo);

#endif // HELPERS_H
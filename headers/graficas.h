#pragma once
#ifndef GRAFICAS_H
#define GRAFICAS_H

#include <Windows.h>
#include <iostream>
#include <string>
#include "../graficas.cpp"
#include "rlutil.h"
#include "helpers.h"
using namespace std;

void enmarcar_texto(string dialogo, int jugador);
void cerdo(int x, string dialog);
void cerdo2(int x, string dialog);
void lines(int x);
void pantalla_generica(int i, int pantalla_cerdo, string dialogo);

#endif // GRAFICAS_H
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

void imprimir_titulo();
void enmarcar_texto(int jugador, string nombre, string dialogo);
void cerdo(int x, string dialogo, string nombre);
void cerdo2(int x, string dialogo, string nombre);
void lines(int x);
void puntaje(string nombre_1, string nombre_2, int jugador_1, int jugador_2);
void pantalla_generica(int i, int pantalla_cerdo, string dialogo, string nombre);
void pantalla_generica_2(int i, string texto, string dialogo, string nombre_1, string nombre_2, int jugador_1, int jugador_2);

#endif // GRAFICAS_H
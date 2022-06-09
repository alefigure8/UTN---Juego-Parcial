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
void lines();
void puntaje(string nombre_jugador_1, string nombre_jugador_2, int *dados_1, int *dados_2,  string texto);
void puntaje_rondas(string nombre_jugador_1, string nombre_jugador_2, int puntos_jugador_1, int puntos_jugador_2,  string texto);
void pantalla_generica(int i, int pantalla_cerdo, string dialogo, string nombre);
void pantalla_generica_2(int i, string texto, string dialogo, string nombre_1, string nombre_2, int jugador_1, int jugador_2);
void imprimir_datos_ronda (int contadorRondas, int totalRonda, int lanzamientos);
int flecha_del_menu();

#endif // GRAFICAS_H
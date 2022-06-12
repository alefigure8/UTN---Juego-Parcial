#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <iostream>
#include <string>
#include "jugadores.h"
#include "../estadisticas.cpp"

void pantalla_puntaje( Jugadores *jugador );
void pantalla_estadistica(Jugadores *jugadores);
void pdv_lanzamientos(int a, int b, int & lanzamientos_jugador_1, int & lanzamientos_jugador_2);
void pdv_oink(int a, int b, int & oinks_jugador_1, int & oinks_jugador_2);
int pdv_cada_50_trufas(int a);
void pdv_trufas_total(int a, int b, int &a_1, int &b_2);
void sumar_punto_historico(int total_jugador_1, int total_jugador_2, int & historico_jugador_1, int & historico_jugador_2);
void separador(int COLUMNA, int FILA);

#endif // ESTADISTICAS_H
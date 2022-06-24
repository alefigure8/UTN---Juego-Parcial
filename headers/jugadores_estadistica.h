#pragma once
#ifndef JUGADORES_ESTADISTICA_H
#define JUGADORES_ESTADISTICA_H

#include "../jugadores_estadistica.cpp"

struct Jugadores_estadistica;
void cargar_jugadores_estadisticas(string jugador, int pdv, Jugadores_estadistica *jugador_estadistica);
void ordenar_vector(Jugadores_estadistica *jugador_estadistica, int cantidad);

#endif // JUGADORES_ESTADISTICA_H
#pragma once
#ifndef JUGADORES_H
#define JUGADORES_H

#include "../jugadores.cpp"

struct Jugadores;
Jugadores inicializar_estructura();
void pedir_nombre(Jugadores *jugadores);
void continuar_jugando(Jugadores &jugadores);

#endif // JUGADORES_H

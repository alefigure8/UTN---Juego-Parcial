#pragma once
#ifndef DADO_H
#define DADO_H

#include "../dado.cpp"

void dibujar_dados(int *num, int cant_dados, int pantalla);
void dados(int a[], int b);
bool dados_iguales (int * dados, int cantidad);
int dado_lado_uno(int * dados, int cantidad);
bool dados_coinciden(int *vec_1, int *vec_2);
int sumar_dados(int vec[3], int CANT_DADOS);

#endif // DADO_H
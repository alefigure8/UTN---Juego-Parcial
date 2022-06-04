#pragma once
#ifndef HELPERS_H
#define HELPERS_H

#include <Windows.h>
#include <iostream>
#include <string>
#include "../helpers.cpp"
using namespace std;

void ResizeConsole(int width, int height);
void colorTexto (int x);
void endLines(int x);
void iniciarMatriz(int matriz[2][3], int filas, int columnas);

#endif // HELPERS_H
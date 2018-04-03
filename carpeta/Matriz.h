/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.h
 * Author: John
 *
 * Created on 2 de abril de 2018, 12:35 PM
 */

#include <iostream>
#include <memory>
#include <string>
using namespace std;

#ifndef MATRIZ_H
#define MATRIZ_H


using namespace std;

class Matriz {
public:
    Matriz(int, int);
    Matriz(const Matriz& orig);
    ~Matriz();

    void agregarElemento(int, int, int);
    int getElemento(int, int);
    int getFila();
    int getColumna();
    Matriz& crearMatrizFrecuencia(int[], int);
    int recorrerMatriz(int, int);
    bool esPosicionValida(int, int);

private:
    int sF[8]{-1, -1, 0, 1, 1, 1, 0, -1};
    int sC[8]{0, 1, 1, 1, 0, -1, -1, -1};
    int fila;
    int columna;
    int** matrizPtr;
};

#endif /* MATRIZ_H */


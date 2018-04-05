/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ampliar.cpp
 * Author: John
 * 
 * Created on 4 de abril de 2018, 07:09 PM
 */

#include "Ampliar.h"

Ampliar::Ampliar() {
}

Ampliar::Ampliar(const Ampliar& orig) {
}

Ampliar::~Ampliar() {
}

Matriz& Ampliar::amplificarMatriz(Matriz& m, int fila, int columna) {

    int tamfila = 2 * fila + 1;
    int tamcolumna = 2 * columna + 1;
    Matriz* matrizAmplificada = new Matriz(tamfila, tamcolumna);

    for (int f = 0; f < tamfila; ++f) {
        for (int c = 0; c < tamcolumna; ++c) {
            matrizAmplificada->setCelda(f, c, -1);
        }
    }


    int dato;
    int contfila = 0;
    int contcolumna = 0;
    for (int f = 0; f < tamfila - 1; f += 2) {
        for (int c = 0; c < tamcolumna - 1; c += 2) {
            dato = m.getCelda(contfila, contcolumna);
            matrizAmplificada->setCelda(f + 1, c + 1, dato);
            ++contcolumna;
        }
        contcolumna = 0;
        ++contfila;
    }


    return* matrizAmplificada;
}

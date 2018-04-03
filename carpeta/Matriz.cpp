/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.cpp
 * Author: John
 * 
 * Created on 2 de abril de 2018, 12:35 PM
 */

#include "Matriz.h"

Matriz::Matriz(int f, int c) {
    fila = f;
    columna = c;
    matrizPtr = new int*[f];
    for (int i = 0; i < f; ++i) {
        matrizPtr[i] = new int[c];
    }
}

Matriz::Matriz(const Matriz& orig) {
}

Matriz::~Matriz() {
    if (matrizPtr != 0) {
        for (int i = 0; i < fila; ++i) {
            delete[] matrizPtr[i];
            cout << "borrando" << endl;
        }
        matrizPtr = 0;
    }
}

void Matriz::agregarElemento(int f, int c, int dato) {
    matrizPtr[f][c] = dato;
}

int Matriz::getElemento(int f, int c) {
    return matrizPtr[f][c];
}

int Matriz::getFila() {
    return fila;
}

int Matriz::getColumna() {
    return columna;
}

Matriz& Matriz::crearMatrizFrecuencia(int v[], int l) {
    
    Matriz* matrizFrecuencia = new Matriz(l,l);

    int dato;
    int cont1 = 0;
    int cont2 = 0;
    for (int f = 0; f < l; ++f) {
        for (int c = 0; c < l; ++c) {
            dato = recorrerMatriz(v[cont1], v[cont2]);
            matrizFrecuencia->agregarElemento(f, c, dato);
            ++cont2;
            cout << matrizFrecuencia->getElemento(f,c) << "\t";
        }
        ++cont1;
        
        cont2 = 0;
    }
    
    return* matrizFrecuencia;
}

int Matriz::recorrerMatriz(int n1, int n2) {

    int frecuencia = 0;
    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            if (matrizPtr[f][c] == n1) {
                for (int v = 0; v < 8; ++v) {
                    if (esPosicionValida(f + sF[v], c + sC[v])) {
                        if (matrizPtr[f + sF[v]][c + sC[v]] == n2) {
                            ++frecuencia;
                        }
                    }
                }
            }
        }
    }
    return frecuencia;
}

bool Matriz::esPosicionValida(int f, int c) {
    return (f >= 0 && f < fila && c >= 0 && c < columna);
}




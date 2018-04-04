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


Matriz::Matriz() {
    matrizPtr = 0;
}

Matriz::Matriz(int f, int c) {
    fila = f;
    columna = c;
    
    matrizPtr = new double*[f];
    for (int i = 0; i < f; ++i) {
        matrizPtr[i] = new double[c];
    }
}


Matriz::~Matriz() {
    if (matrizPtr != 0) {
        for (int i = 0; i < fila; ++i) {
            delete[] matrizPtr[i];
            cout << "borrando" << endl;
        }
        delete[] matrizPtr;
        matrizPtr = 0;
    }
}


//Falta crear el constructor que recibe la matriz del archivo .txt para que la
//apunte con el puntero this->matrizPtr
Matriz::Matriz(const Matriz& m){

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
    Matriz* matrizFrecuencia = new Matriz(l, l);


    int dato;
    int cont1 = 0;
    int cont2 = 0;
    for (int f = 0; f < l; ++f) {
        for (int c = 0; c < l; ++c) {
            dato = recorrerMatriz(v[cont1], v[cont2]);
            matrizFrecuencia->agregarElemento(f, c, dato);
            ++cont2;
        }
        ++cont1;
        cont2 = 0;
    }

    return* matrizFrecuencia;
}

int Matriz::recorrerMatriz(int n1, int n2) {
    Matriz* mascara = new Matriz(fila, columna);

    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            mascara->matrizPtr[f][c] = 1;
        }
    }

    int frecuencia = 0;
    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            if (matrizPtr[f][c] == n1) {
                if (n1 == n2) {
                    mascara->matrizPtr[f][c] = 0;
                    ++frecuencia;
                }
                for (int v = 0; v < 8; ++v) {
                    if (esPosicionValida(f + sF[v], c + sC[v]) && mascara->matrizPtr[f + sF[v]][c + sC[v]] == 1) {
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

Matriz& Matriz::multiplicarMatriz(const Matriz& m, int l) {
    Matriz* multiplicada = new Matriz(l, l);

    int sumatoria;
    for (int f = 0; f < l; ++f) {
        for (int c = 0; c < l; ++c) {
            sumatoria = 0;
            for (int p = 0; p < l; ++p) {
                sumatoria += m.matrizPtr[p][c] * m.matrizPtr[f][p];
            }
            multiplicada->matrizPtr[f][c] = sumatoria;
        }
    }

    return* multiplicada;
}

Matriz& Matriz::crearMatrizNormalizada(Matriz& m, int n) {
    Matriz* normalizada = new Matriz(n, n);

    double dato;
    for (int f = 0; f < n; ++f) {
        for (int c = 0; c < n; ++c) {
            dato = (2 * (m.matrizPtr[f][c])) / (m.matrizPtr[f][f] + m.matrizPtr[c][c]);
            normalizada->matrizPtr[f][c] = dato;
        }
    }

    return* normalizada;
}

bool Matriz::esPosicionValida(int f, int c) {
    return (f >= 0 && f < fila && c >= 0 && c < columna);
}

void Matriz::imprimirMatriz(){
    for (int f = 0; f < 3; ++f) {
        for (int c = 0; c < 3; ++c) {
            cout << matrizPtr[f][c];
            cout << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}



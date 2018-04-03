/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: John
 *
 * Created on 2 de abril de 2018, 12:28 PM
 */

#include <memory>
#include <sstream>
#include "Matriz.h"
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
/*
    Matriz* matriz = new Matriz(3, 3);

    int cont = 0;
    for (int f = 0; f < 3; ++f) {
        for (int c = 0; c < 3; ++c) {
            matriz->agregarElemento(f, c, cont);
            ++cont;
        }
    }

    for (int f = 0; f < 3; ++f) {
        for (int c = 0; c < 3; ++c) {
            cout << matriz->getElemento(f, c) << "\t";
        }
        cout << "\n";
    }

    cout << "\n" << matriz->getFila() << endl;
    cout << "\n" << matriz->getColumna() << endl;
*/
    //delete matriz;

    Matriz* matriz = new Matriz(3, 3);

    matriz->agregarElemento(0, 0, 1);
    matriz->agregarElemento(0, 1, 1);
    matriz->agregarElemento(0, 2, 3);
    matriz->agregarElemento(1, 0, 2);
    matriz->agregarElemento(1, 1, 2);
    matriz->agregarElemento(1, 2, 1);
    matriz->agregarElemento(2, 0, 1);
    matriz->agregarElemento(2, 1, 3);
    matriz->agregarElemento(2, 2, 2);

    for (int f = 0; f < 3; ++f) {
        for (int c = 0; c < 3; ++c) {
            cout << matriz->getElemento(f, c) << "\t";
        }
        cout << "\n";
    }
    
    int v[3] = {1,2,3};
    
    Matriz matrizFrecuencia = matriz->crearMatrizFrecuencia(v,3);
    
    
    for (int f = 0; f < 3; ++f) {
        for (int c = 0; c < 3; ++c) {
            cout << matrizFrecuencia.agregarElemento(f,c) << "\t";
        }
        cout << "\n";
    }

    delete matriz;


    return 0;
}


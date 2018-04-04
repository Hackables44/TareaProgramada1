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
    
    
    //Prueba realizada para representar el ejemplo del ejercicio
    Matriz matriz(Matriz(3, 3));
    matriz.agregarElemento(0, 0, 1);
    matriz.agregarElemento(0, 1, 1);
    matriz.agregarElemento(0, 2, 2);
    matriz.agregarElemento(1, 0, 3);
    matriz.agregarElemento(1, 1, 2);
    matriz.agregarElemento(1, 2, 1);
    matriz.agregarElemento(2, 0, 3);
    matriz.agregarElemento(2, 1, 1);
    matriz.agregarElemento(2, 2, 3);

    matriz.imprimirMatriz();

    int v[3] = {1,2,3};
    
    Matriz matrizFrecuencia;
    Matriz matrizMultiplicada;
    Matriz matrizNormalizada;
    
    matrizFrecuencia = matriz.crearMatrizFrecuencia(v, 3);
    matrizMultiplicada = matriz.multiplicarMatriz(matrizFrecuencia, 3);
    matrizNormalizada = matriz.crearMatrizNormalizada(matrizMultiplicada, 3);
    
    matrizFrecuencia.imprimirMatriz();
    matrizMultiplicada.imprimirMatriz();
    matrizNormalizada.imprimirMatriz();
    
    return 0;
}


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
#include <sstream>
using namespace std;


#ifndef MATRIZ_H
#define MATRIZ_H


using namespace std;

class Matriz {
public:
    
    //Construye una instancia de Matriz, donde el puntero de matriz apunta a nulo
    Matriz();
    
    //Construye una instancia de Matriz, donde el puntero de matriz apunta a una seccion de memoria con arreglo de 2 dimensiones
    Matriz(int, int);
    
    //Falta construir el constructor que recibe la matriz formada del archivo .txt
    Matriz(const Matriz&);
    
    //Devuelve la memoria al sistema de donde se encuentra el arreglo de 2 dimensiones
    ~Matriz();

    //Agrega un elemento en el arreglo de 2 dimensiones que es apuntado por el puntero de matriz
    //En los métodos no se utiliza, se puede acceder directamente al dato
    //Aunque en el main si es necesario utilizarlo
    void agregarElemento(int, int, int);
    
    //Retorna un elemento que se encuentre en el arreglo de 2 dimensiones que es apuntado por el puntero de matriz
    //En los métodos no se utiliza, se puede acceder directamente al dato que se desea solicitar
    //Aunque en el main si es necesario utilizarlo
    int getElemento(int, int);
    
    //Retorna la longitud de la fila en el arreglo de 2 dimensiones
    int getFila();
    
    //Retorna la longitud de la columna en el arreglo de 2 dimensiones
    int getColumna();
    
    //Retorna una referencia a una seccion de memoria solicitada dentro del método, la cual contiene un arreglo de 2 dimensiones
    //con las frecuencias con las que 2 elementos estan a la par el uno del otro en la matriz This*
    Matriz& crearMatrizFrecuencia(int[], int);
    
    //Es un método de control que utiliza el método "crearMatrizFrecuencia()"
    //Retorna cada una de las frecuencias, las cuales son almacenadas dentro del arreglo contenido en el método "crearMatrizFrecuencia()"
    int recorrerMatriz(int, int);
    
    //Retorna una referencia a una seccion de memoria solicitada dentro del método, la cual contiene un arreglo de 2 dimensiones
    //con los resultados de multiplicar la matriz This* consigo misma
    Matriz& multiplicarMatriz(const Matriz&, int);
    
    //Retorna una referencia a una seccion de memoria solicitada dentro del método, la cual contiene un arreglo de 2 dimensiones
    //con los resultados de aplicar la fórmula a cada uno de los elementos en This*
    Matriz& crearMatrizNormalizada(Matriz&, int);
    
    //Analiza si la pocision a la que se quiere mover existe dentro de la matriz This*
    bool esPosicionValida(int, int);
    
    //Imprime This* en consola
    void imprimirMatriz();
    
    
private:
    int sF[8]{-1, -1, 0, 1, 1, 1, 0, -1};
    int sC[8]{0, 1, 1, 1, 0, -1, -1, -1};
    int fila;
    int columna;
    double** matrizPtr;
    //static Matriz* retornaPtr;
};

#endif /* MATRIZ_H */


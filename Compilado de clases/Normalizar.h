/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Normalizar.h
 * Author: John
 *
 * Created on 4 de abril de 2018, 07:08 PM
 */

#include "Matriz.h"


#ifndef NORMALIZAR_H
#define NORMALIZAR_H

class Normalizar {
public:
    Normalizar();
    Normalizar(const Normalizar& orig);
    ~Normalizar();
    
    Matriz& crearMatrizFrecuencia(Matriz&, Vector&, int);
    
    int recorrerMatriz(Matriz&, int, int);
    
    Matriz& multiplicarMatriz(Matriz& , int );
    
    Matriz& crearMatrizNormalizada(Matriz&, int);
    
    bool esPosicionValida(Matriz&, int, int);
    
    
private:

};

#endif /* NORMALIZAR_H */


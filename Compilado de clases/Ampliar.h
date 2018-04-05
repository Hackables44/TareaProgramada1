/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ampliar.h
 * Author: John
 *
 * Created on 4 de abril de 2018, 07:09 PM
 */

#include "Matriz.h"

#ifndef AMPLIAR_H
#define AMPLIAR_H

class Ampliar {
public:
    Ampliar();
    Ampliar(const Ampliar& orig);
    ~Ampliar();
    
    Matriz& amplificarMatriz(Matriz&, int fila, int columna);
    
private:

};

#endif /* AMPLIAR_H */


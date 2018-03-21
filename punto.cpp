#include "Punto.h"

#include<iostream>
using namespace std;
/**
comentarios multilinea igual que en Java...
**/

// El delimitador de alcance :: define a que clase pertenece el objeto

Punto::Punto(int x,int y){
	this->x = x;  
	this->y = y;
}

void Punto::ver(){
	cout << "(" << x << "," << y << ")" << endl;
}

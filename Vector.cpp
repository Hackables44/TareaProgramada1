// Vector.cpp	Contiene la implementación de la clase Vector
#include "Vector.h"
#include <iostream> // permite realizar operaciones de entrada y salida

using namespace std;

Vector::Vector(int n){ // constructor Vector
	this-> n= n; // se inicializa la variable n que representa el tamaño del vector
	vecPtr = new int[n];
	for(int i = 0; i < n; ++i){ // recorrido del vector
		vecPtr[i]=0; // Se inicializa las celdas en 0
   }
 }

 Vector::~Vector(){ // Destructor del objeto vector
 	// Si el el puntero al vector no es nulo elimino el vector de enteros al que le apunta
    if(vecPtr!=0){
 	   delete [] vecPtr;   // eliminar todos los enteros a los que le apunta el puntero vectorPtr
 	   vecPtr = 0; // Se pone en 0 para no invocar dos veces el destructor
    }
 }

 void Vector::ver(){ // Método para imprimir el objeto vector
	cout << "{";
	for(int i = 0; i < n; ++i){
		cout << " "<< vecPtr[i];
	}
	cout << "}" << endl;
}

 bool Vector::comparar(int valor){ // Método para comprobar si el valor ya está almacenado en el vector
  this->valor=valor; // se inicializa la variable valor
  int i =0; // se inicializa la variable i como contador para recorrer el vector
  bool existe = false; // se inicializa para la variable existe
 	bool fin = false; // se inicializa la variable fin para saber si ya terminó de recorrer el vector

  while (existe == false && fin == false){ // Recorrer el vector mienstras el valor no se haya encontrado en el vector y no haya llegado al límite del vector
    if (i<n) { // n es el tamaño del vector
      if (vecPtr[i] ==valor){ //compara el valor con cada celda del vector
   			existe = true;
   		}
      else{
        i++; // aumento de la variable i
      }
    }
    else{
      fin = true;
    }
  }
  return existe; // retorna false/true dependiendo si el valor se haya encontrado en el vector
 }

 void Vector::agregar(int i,int valor){ // Metodo para almecenar un valor en el vector
	if(i >=0 && i < n){ // verifica si la posición es válida
		vecPtr[i] = valor;
	}
}

int Vector::get(int i){ // Método para obtener el valor de una celda
	int valor = -1;
	if(i >=0 && i < n){
		valor = vecPtr[i];
	}
	else {
	    cerr << "Posicion inválida en vector, se retorna valor -1 por omisión"<< endl;
	}
    return valor;
}

// Matriz.cpp	Contiene la implementación de la clase Matriz
#include "Matriz.h" // importa la cabecera que contiene la definición de la clase
#include <iostream> // permite realizar operaciones de entrada y salida
#include <stdlib.h> // permite el uso de new y delete
using namespace std;

// Utilizamos el operador de resolución de ámbito para indicar a donde pertenece la implementación de los métodos, en este caso a la clase Matriz
Matriz::Matriz(int filas, int columnas){ // constructor
	// almacenamos el tamaño de las dimensiones
	this->filas=filas; // inicializo la variable de instancia filas
	this->columnas=columnas; // inicializo la variable de instancia columnas

	// creamos (asignamos e inicializamos) la matriz
	m = new int * [filas]; // asigna un vector de punteros con la extensión de filas; crea una dimensión
	for(int f=0; f<filas; ++f){ // recorre el vector de punteros
		m[f] = new int [columnas]; // asigna la dirección de la primera celda de un vector de números; va creando la segunda dimensión
		for(int c=0; c<columnas; ++c){ // recorre las celdas
			m[f][c] = 0; // inicializo las celdas en 0
		} // fin de la estructura iterativa for anidada
	} // fin de la estructura iterativa for

} // fin del constructor Matriz

Matriz::~Matriz(){ // destruye el objeto Matriz
	// elimina la matriz. Si el puntero al vector no es nulo, elimino el vector de punteros al que apunta (hace referencia)
	if(m!=0){ // si el puntero es de diferente de 0, si no es un puntero nulo
		for(int f=0; f<filas; ++f){ // recorre el vector de punteros; la primera dimensión
			delete [] m[f]; // va eliminando el vector de enteros de la posición
		} // fin de la estructura for anidada
		delete []m; // elimina el vector de punteros
		m = 0; // se pone en 0 para no invocar 2 veces el destructor
	} // fin de la condición que verifica si el puntero no es nulo
} // fin del destructor

// verifica que la celda inidcada esté dentro de la matriz
bool Matriz::posValida(int f, int c){
	bool valida = false; // declaramos la variable local "valida" y la inicializamos en falso
	if(f>=0 && f<filas && c>=0 && c<columnas){ // si la celda ingresada es válida
		valida = true; // cambiamos su valor de verdad
	}
	return valida; // devuelve el resultado
} // fin de la función posVálida

// asigna un número a una posición indicada dentro de la matriz
void Matriz::setCelda(int fila, int columna, int numero){
	if(posValida(fila,columna)){ // si la posición indicada está dentro de la matriz
		m[fila][columna] = numero; // asigno el número entero a la celda indicada
	} // fin de la condicional
} // fin del método set

int Matriz::getCelda(int fila, int columna){
	int numero = 0; // declaro e inicializo la variable numero
	if(posValida(fila, columna)){ // verifica que la posición ingresada sea válida
		numero = m[fila][columna]; // almaceno el valor de la celda
	}
	else{ // si la posición es inválida, despliego un mensaje de error
		cerr << "Warning: La posición ingresada [" << fila << "][" << columna << "] es invalida." << " Se devuelve 0 por omisión." << endl;
	}
	return numero; // devuelve el número entero
} // fin de la función get

int Matriz::getFilas(){ // obtiene la cantidad de filas de la matriz
	return filas; // devuelve el valor de la variable de instancia filas
} // fin de la función getFilas

int Matriz::getColumnas(){ // obtiene la cantidad de columnas de la matriz
	return columnas; // devuelve el valor de la variable de instancia columnas
} // fin de la función getColumnas

void Matriz::verMatriz(){ // imprime en pantalla el arreglo de 2 dimensiones
	// el for externo recorre las filas y el for interno las columnas; mientras imprime los valores en las celdas respectivas
	for(int f=0; f<filas; ++f){
		for(int c=0; c<columnas; ++c){
			cout << m[f][c] << " "; // imprime los valores en las celdas y deja un espacio  en blanco
		} // fin de la estructura iterativa for anidada
		cout << endl; // cambio de línea
	} // fin de la estructura iterativa for
	cout << endl; // deja una línea en blanco después de mostrar la matriz
} // fin de la función verMatriz

//En proceso
int Matriz::calcularFrecuencia(){
	int f;  //???
	int c;  //??
	int i; //???
  int frecuencia = Matriz::recursivo(f,c,i);//donde i es el numero al que se le quiere sacar la frecuencia
  return frecuencia;
}

//
int Matriz::recursivo(int f, int c,int i){
  //int frecuencia = 0;    ahi veo si la inicializo aqui
  int controlador = 0;// no sé si esto será necesario pero no lo pienso de otra forma
  if(Matriz::posValida(f,c) && m[f][c] == i ){//si es posicion valida y el numero que es analizado es igual al del lugar de la matriz auntar 1 al contador de frecuencia
    ++frecuencia;
  }
switch(controlador){//para entrar a los diferentes llamados recursvos
  case 0 : controlador = 1;
  Matriz::recursivo(f-1,c,i);
  break;
  case 1 : controlador = 2;
  Matriz::recursivo(f-1,c+1,i);
  break;
  case 2 : controlador = 3;
  Matriz::recursivo(f,c+1,i);
  break;
  case 3 : controlador = 4;
  Matriz::recursivo(f+1,c+1,i);
  break;
  case 4 : controlador = 5;
  Matriz::recursivo(f+1,c,i);
  break;
  case 5 : controlador = 6;
  Matriz::recursivo(f+1,c-1,i);
  break;
  case 6 : controlador = 7;
  Matriz::recursivo(f,c-1,i);
  break;
  case 7 : //controlador = 0; ???
  Matriz::recursivo(fila-1,c-1,i);
  break;
 }
}

void Matriz::sacarTranspuesta(){
	transpuesta = new int * [columnas];
	for(int f=0; f<columnas; ++f){
		transpuesta[f] = new int [filas];
		for(int c=0; c<filas; ++c){
			transpuesta[f][c] = 0;
		}
	}

	for(int f = 0;f < fila;++f){
		for(int c = 0;c<columna;++c){
		transpuesta[c][f] = m[f][c];
		}
	}
}

void Matriz::productoDeMatrices(){

producto = new int * [filas]
	for(int f = 0;f < fila;++f){
		producto[f] = new int [filas]
    for(int c = 0;c<fila;++c){
      producto[f][c] = 0;

    }
  }

for(int i = 0;i < fila ;++i){
  for(int f = 0;f < fila;++f){
    for(int c = 0;c<columna;++c){
    producto[i][f] += m[i][c] * transpuesta[c][f];
    }
  }
}
}

void Matriz::crearMatrizFrecuencia(){

	for(int i = 0; i< fila*columna + 1;++i){
    for(int f = 0;f< fila;++f){
      for(int c = 0; c<columna; ++c){
        if(controlador == 1){
          if(m[f][c] == 0){
            ++count;
            controlador = 0;
          }
        }
        else{
          if(m[f][c] != 0){
            if(variable == 0){
              variable = m[f][c];
              ++count;
            }
            else{
              if(variable == m[f][c]){
                m[f][c] = 0;
              }
            }
          }

        }
      }
    }
    controlador = 0;
    variable = 0;
  }
	int frecuencia = new int *[count];
	int frecuencia[count] = new int [count]; 
}

	void Matriz::crearMatrizAsociativa(){
		asociativa = new int *[fila];
		for(int f = 0;f < fila;++f){
			asociativa[f] = new int [fila];
	    for(int c = 0;c<fila;++c){
	    asociativa[f][c] = (double) 2 * producto[f][c] / (producto[f][f] + producto[c][c]);
	    }
	  }
	};

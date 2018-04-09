
// Matriz.cpp	Contiene la implementación de la clase Matriz
#include "Matriz.h" // importa la cabecera que contiene la definición de la clase
#include "Vector.h"
#include <iostream> // permite realizar operaciones de entrada y salida

using namespace std;

Matriz::Matriz(){
    
    m = 0;
    matrizFrecuencia = 0;
}

// Utilizamos el operador de resolución de ámbito para indicar a donde pertenece la implementación de los métodos, en este caso a la clase Matriz
Matriz::Matriz(int filas, int columnas){ // constructor
	// almacenamos el tamaño de las dimensiones
	this->filas=filas; // inicializo la variable de instancia filas
	this->columnas=columnas; // inicializo la variable de instancia columnas

	// creamos (asignamos e inicializamos) la matriz
	m = new double* [filas]; // asigna un vector de punteros con la extensión de filas; crea una dimensión
	for(int f=0; f<filas; ++f){ // recorre el vector de punteros
		m[f] = new double [columnas]; // asigna la dirección de la primera celda de un vector de números; va creando la segunda dimensión
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
void Matriz::setCelda(int fila, int columna, double numero){
	if(posValida(fila,columna)){ // si la posición indicada está dentro de la matriz
		m[fila][columna] = numero; // asigno el número entero a la celda indicada
	} // fin de la condicional
} // fin del método set

double Matriz::getCelda(int fila, int columna){
	double numero = 0; // declaro e inicializo la variable numero
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
			cout << m[f][c] << "\t"; // imprime los valores en las celdas y deja un espacio  en blanco
		} // fin de la estructura iterativa for anidada
		cout << endl; // cambio de línea
	} // fin de la estructura iterativa for
	cout << endl; // deja una línea en blanco después de mostrar la matriz
} // fin de la función verMatriz

Vector& Matriz::crearVectorNumDiferentes(){ // Método que crea el vector que almacena cada número diferente de la mtariz de Imagen
	int contador = 0; // inicializa la variale contador para llevar la cuenta de números diferentes de la Matriz
	Vector vector(filas*columnas); // creamos una instancia de objeto Vector
	//vector.ver();
	int valor = 0;  // se inicializa la variable valor
	int num =0; //se inicializa la variable num
	bool yaExiste = false;
	for (int f = 0; f < filas; f++) {
		for (int c = 0; c < columnas; c++) {
			valor = m[f][c]; //se va almancenado en la variable valor, el numero de cada celda de la matriz
			if(valor != 0){ //si el valor es diferente a cero
			yaExiste =	vector.comparar(valor); //se verifica si el vector ya existe en el vector
			if (yaExiste == false) {
				vector.agregar(contador, valor); //si no existe se guarada en el vector
				contador++;
			}
			else{
				yaExiste=false;
			}
			}
		}
	}
	//cout << contador << endl;
	Vector* vector2 = new Vector(contador); //se crear otra instancia de objecto vector para reducir la memoria
	for(int i=0; i<contador; ++i){  //se pasa cada elemento del 1º vector al vector2.
		num = vector.get(i);
		vector2->agregar(i, num);
	}
		//vector2.ver(); //imprime el vector
        
        return* vector2;
}
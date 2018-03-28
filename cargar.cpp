/// cargar.cpp
// importar las librerías necesarias para el manejo de flujos de bytes y, operaciones de entrada y salida
#include <fstream> // permite leer bytes
#include <iostream> // permite realizar operaciones de entrada y salida

using namespace std; // permite utilizar todos los nombre de cualquier librería estándar de C++

int main( int argc, char ** argv ){
	cout << "Cantidad de parametros: " << argc << endl; // indica la cantidad de parámetros
	for(int i=0; i<argc; ++i){
		cout << "argumento " << i << ": " << argv[i] << endl; // imprime los parámetros ingresados
	} // fin de la estructura iterativa for
	cout << endl; // imprime una línea en blanco
	
	int filas; // almacenará las filas de la matriz
	int columnas; // almacenará las columnas de la matriz
	char * nombre; // almacenará el nombre del archivo (o ruta) al que extraerá los bytes
	
	// almacena el nombre del archivo al cual extrar los bytes y la cantidad de veces que se duplicará la matriz
	if(argc>2){ // si hay más de 2 parámetros
		nombre = argv[1]; // tome el segundo parámetro
		duplicar = argv[2]; // almacena la cantidad de veces que se va a duplicar la matriz
	}
	else{
		nombre = (char *) "datos.txt"; // asigna el nombre de un archivo por defecto; realiza un parsing
		duplicar = 2;
	} // fin de la doble bicondicional
	
	cout <<  "Archivo: " << nombre << endl << "Cantidad de veces a duplicar: " << duplicar << endl;
	
	fstream entrada(nombre); // una instancia de objeto fstream, extrae los bytes del archivo indicado
	
	// determino las dimensiones de la matriz leyendo las 2 primeros enteros (utilizo el operador de extracción) Ojo
	entrada >> filas; // lee el primer entero
	entrada >> columnas; // sigue con el segundo entero
	
	// crea la matriz por medio de punteros (crea un vector de vectores); es un vector de punteros a vectores de números
	int * * m; // es un puntero de punteros
	m = new int * [filas];// asigno un vector de punteros
	for(int f=0; f<filas; ++f){ // recorre el vector que representa la primera celda de cada filas
		m[f]=new int[columnas]; // a cada puntero le asigno la referencia a la primera celda de un vector de enteros; con lo que se va creando la segunda dimensión
		for(int c=0; c<columnas; ++c){ // conforme crea la segunda dimesión; asimismo recorre las celdas para asignar valores
			entrada >> m[f][c]; // asigna los bytes (en este caso números) restantes
		} // termina de recorrer la segunda dimensión
	} // fin de la estructura repetitiva
	
	// recorre la matriz mientras elimina los vectores
	for(int f=0; f<filas; ++f){ // recorre el vector de los punteros a los otros vectores
		for(int c=0; c<columnas; ++c){ // recorre el vector de enteros mientras imprime sus números
			cout << m[f][c] << " "; // imprime el valor en la celda
		} // fin del recorrido del vector de enteros
		delete [] m[f]; // va eliminado las filas; elimina todo el vector al que hace referencia el puntero de una celda determinada
		cout << endl; // cambia de línea
	} // termina de recorrer el vector de punteros
	delete [] m; // elimina el vector de punteros
} // fin de la función principal

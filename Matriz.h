// Matriz.h		Cabecera de la clase Matriz
#ifndef _MATRIZ // el preprocesador condicional determina la compilación condicional, si _MATRIZ no está definida que la defina (es como una bandera) y compile; incluye el código hasta #endif
#define _MATRIZ // define la macros 

class Matriz{
	// definición de la clase MAtriz
	private: // especificador de acceso privado
		// variables de intancia o atributos
		int filas; // almacena la cantidad de filas de la matriz (define una dimensión)
		int columnas; // almacenará la cantidad de columnas de la matriz (define la otra dimensión)
		int * * m; // almacenará la matriz; es puntero de punteros
		
	public: // especificador de acceso público
	Matriz(int, int); // constructor que recibe la cantidad de filas y columnas
	~Matriz(); // destructor del objeto Matriz
	bool posValida(int , int); // verifica que la celda indicada tenga una posición válida
	void setCelda(int, int, int); // set que recibe la posición de la celda y el número a asignar
	int getCelda(int, int); // get recibe como parámetros la posición de la celda
	int getFilas(); // devuelve la cantidad de filas de la matriz
	int getColumnas(); // devuelve la cantidad de columnas de la matriz
	void verMatriz(); // imprime en pantalla el contenido del arreglo;
}; // fin de la definición de la clase

#endif // fin del prepocesador condicional

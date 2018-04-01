// Matriz.h		Cabecera de la clase Matriz
#ifndef _MATRIZ // el preprocesador condicional determina la compilación condicional, si _MATRIZ no está definida que la defina (es como una bandera) y compile; incluye el código hasta #endif
#define _MATRIZ // define la macros

class Matriz{
	// definición de la clase MAtriz
	private: // especificador de acceso privado
		// variables de intancia o atributos
		int filas; // almacena la cantidad de filas de la matriz (define una dimensión)
		int columnas; // almacenará la cantidad de columnas de la matriz (define la otra dimensión)
    		int n; //length de la matriz
		int * * m; // almacenará la matriz; es puntero de punteros
		int * * transpuesta; // matriz transpuesta de la de frecuencia
		int * * producto; // resultado del producto entre la matriz de frecuencia y su transpuesta
		int * * frecuencia; // matriz de frecuencia
		int count = 0; //contador para crear la matriz de frecuencia
		int variable = 0;
		int controlador = 1;

	public: // especificador de acceso público
		Matriz(int, int); // constructor que recibe la cantidad de filas y columnas
		~Matriz(); // destructor del objeto Matriz
		bool posValida(int , int); // verifica que la celda indicada tenga una posición válida
		void setCelda(int, int, int); // set que recibe la posición de la celda y el número a asignar
		int getCelda(int, int); // get recibe como parámetros la posición de la celda
		int getFilas(); // devuelve la cantidad de filas de la matriz
		int getColumnas(); // devuelve la cantidad de columnas de la matriz
		void verMatriz(); // imprime en pantalla el contenido del arreglo;
		int calcularFrecuencia(); //retorna la cantidad de frecuencia total al numero a analizar
		int recursivo(int,int,int); //es el metodo recursivo que se encarga de calcular la frecuencia
		void sacarTranspuesta(); //sacar la matriz transpuesta
		void productoDeMatrices(); //multiplicacion de matriz normal por la transpuesta
		void crearMatrizFrecuencia(); // crea la matriz de frecuencias
}; // fin de la definición de la clase

#endif // fin del prepocesador condicional

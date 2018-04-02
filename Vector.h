// Vector.h		Cabecera de la clase Vector
#ifndef _VECTOR // el preprocesador condicional determina la compilación condicional, si _MATRIZ no está definida que la defina (es como una bandera) y compile; incluye el código hasta #endif
#define _VECTOR // define la macros

class Vector{
	// definición de la clase Vector
	private: // especificador de acceso privado
		// variables de intancia o atributos
		int * vecPtr; //Direccion del primero entero de vector
		int n; //longitud del vector
		int valor; //valor que se almacenará en el vector

	public: // especificador de acceso público

	Vector(int); // constructor de Vector que recibe como parametro cantidad de celdas

	~Vector(); // destructor del vector
  void ver(); // imprime el vector
  bool comparar(int); //recibe un valor y lo compara con cada elemento del vector
  void agregar(int , int); // recibe la posición de la celda y el número a asignar
	int get(int); // devuelve el valor de una celda


}; // fin de la definición de la clase

#endif // fin del prepocesador condicional

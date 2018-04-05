// Normalizar.h		Cabecera de la clase Normalizar

#include "Matriz.h"

#ifndef NORMALIZAR_H
#define NORMALIZAR_H

class Normalizar {
public:
	// constructores de la clase Normalizar
    Normalizar();
    Normalizar(const Normalizar& orig);
    ~Normalizar(); // destructor de la clase Normalizar
	
    Matriz& crearMatrizFrecuencia(Matriz&, Vector&, int); // recibe una referencia a la matriz original, la cantidad de números diferentes junto con el length del vector

    int recorrerMatriz(Matriz&, int, int); // recorre la matriz para ir obteniendo la frecuencia de apariciones entre dos números enteros

    Matriz& multiplicarMatriz(Matriz& , int ); // recibe referencia de la matriz que almacena las frecuencias y obtiene sus dimensiones (es una matriz cuadrada)

    Matriz& crearMatrizNormalizada(Matriz&, int); // recibe referencia a la matriz producto de las frecuencias con su transpuesta, con sus dimensiones (cuadrada)

    bool esPosicionValida(Matriz&, int, int); // verifica que no se vaya a salir de la matriz, a otras direcciones de memoria


private:

};

#endif /* NORMALIZAR_H */

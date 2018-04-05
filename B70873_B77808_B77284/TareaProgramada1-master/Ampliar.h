// Ampliar.h		Cabecera de la clase Ampliar

#include "Matriz.h"

#ifndef AMPLIAR_H
#define AMPLIAR_H

class Ampliar {
public: // especificador de acceso público
	// constructores de la clase
    Ampliar();
    Ampliar(const Ampliar& orig);
    ~Ampliar();

    Matriz& amplificarMatriz(Matriz&, int fila, int columna); // duplica la matriz y ordena los valores de la matriz original

private:

};

#endif /* AMPLIAR_H */

// Ampliar.h		Cabecera de la clase Ampliar

#include "Matriz.h"

#ifndef AMPLIAR_H
#define AMPLIAR_H

class Ampliar {
public:
    Ampliar();
    Ampliar(const Ampliar& orig);
    ~Ampliar();

    Matriz& amplificarMatriz(Matriz&, int fila, int columna);

private:

};

#endif /* AMPLIAR_H */

// Normalizar.h		Cabecera de la clase Normalizar

#include "Matriz.h"

#ifndef NORMALIZAR_H
#define NORMALIZAR_H

class Normalizar {
public:
    Normalizar();
    Normalizar(const Normalizar& orig);
    ~Normalizar();

    Matriz& crearMatrizFrecuencia(Matriz&, Vector&, int);

    int recorrerMatriz(Matriz&, int, int);

    Matriz& multiplicarMatriz(Matriz& , int );

    Matriz& crearMatrizNormalizada(Matriz&, int);

    bool esPosicionValida(Matriz&, int, int);


private:

};

#endif /* NORMALIZAR_H */


#include "Matriz.h"
#include "Vector.h"
using namespace std;

#ifndef RELLENAR_H
#define RELLENAR_H

class Rellenar {
public:
    Rellenar();
    Rellenar(const Rellenar& orig);
    ~Rellenar();
        
    Matriz& rellenarMatriz(Matriz&, Matriz&, Vector&);
    int hallarPosicion(Vector&, int);
    int hallarPosicionMayor(Matriz&, int);
    int hallarPosicionMayor(Matriz&, int, int);
    int mejorVecino(Matriz&, Matriz&, Vector&, int, int);
    bool esPosicionValida(Matriz&, int, int);
private:
        

};

#endif /* RELLENAR_H */



#include "Matriz.h"
#include "Rellenar.h"
#include "Normalizar.h"

#ifndef AMPLIAR_H
#define AMPLIAR_H

class Ampliar {
public:
    Ampliar();
    Ampliar(const Ampliar& orig);
    ~Ampliar();
    
    Matriz& amplificarMatriz(Matriz&, int, int);
    
    Matriz& agrandarMatriz(Matriz&, int);
    
private:

};

#endif /* AMPLIAR_H */


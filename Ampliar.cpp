// Ampliar.h		Cabecera de la clase Ampliar

#include "Ampliar.h"

Ampliar::Ampliar() {
}

Ampliar::Ampliar(const Ampliar& orig) {
}

Ampliar::~Ampliar() {
}

Matriz& Ampliar::amplificarMatriz(Matriz& m, int fila, int columna) {

    int tamFila = 2 * fila + 1;
    int tamColumna = 2 * columna + 1;
    Matriz* matrizAmplificada = new Matriz(tamFila, tamColumna);

    for (int f = 0; f < tamFila; ++f) {
        for (int c = 0; c < tamColumna; ++c) {
            matrizAmplificada->setCelda(f, c, -1);
        }
    }


    int dato;
    int contFila = 0;
    int contColumna = 0;
    for (int f = 0; f < tamFila - 1; f += 2) {
        for (int c = 0; c < tamColumna - 1; c += 2) {
            dato = m.getCelda(contFila, contColumna);
            matrizAmplificada->setCelda(f + 1, c + 1, dato);
            ++contColumna;
        }
        contColumna = 0;
        ++contFila;
    }


    return* matrizAmplificada;
}

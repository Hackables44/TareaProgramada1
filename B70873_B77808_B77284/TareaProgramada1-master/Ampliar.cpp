// Ampliar.cpp	

#include "Ampliar.h"

Ampliar::Ampliar() { // constructor predeterminado de la clase (sin parámetros)
}

Ampliar::Ampliar(const Ampliar& orig) { // constructor que recibe la referencia de un objeto Ampliar, el cual no será modificado
}

Ampliar::~Ampliar() { // destructor de la clase Ampliar
}

Matriz& Ampliar::amplificarMatriz(Matriz& m, int fila, int columna) { // duplica el tamaño de la matriz
	// Calcula las nuevas dimensiones y crea la matriz duplicada
    int tamFila = 2 * fila + 1;
    int tamColumna = 2 * columna + 1;
    Matriz* matrizAmplificada = new Matriz(tamFila, tamColumna);

	// inicializa las celdas con el valor -1
    for (int f = 0; f < tamFila; ++f) {
        for (int c = 0; c < tamColumna; ++c) {
            matrizAmplificada->setCelda(f, c, -1);
        }
    }

	
	// coloca los números de la matriz original en la matriz ampliada
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


    return* matrizAmplificada; // devuelve referencia a la matrizAmplificada
}

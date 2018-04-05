// Normalizar.cpp
#include "Normalizar.h"

Normalizar::Normalizar() {
}

Normalizar::Normalizar(const Normalizar& orig) {
}

Normalizar::~Normalizar() {
}

Matriz& Normalizar::crearMatrizFrecuencia(Matriz& m, Vector& v, int a){

    Matriz* matrizFrecuencia = new Matriz(a, a); //crea una matriz usando el tamaño del vector


    int dato;
    int cont1 = 0;
    int cont2 = 0;
    for (int f = 0; f < a; ++f) {
        for (int c = 0; c < a; ++c) {
            dato = recorrerMatriz(m, v.get(cont1), v.get(cont2));
            matrizFrecuencia->setCelda(f, c, dato);
            ++cont2;
        }
        ++cont1;
        cont2 = 0;
    }

    return* matrizFrecuencia;
}

int Normalizar::recorrerMatriz(Matriz& m, int n1, int n2){
	// obtiene las dimensiones
    int fila = m.getFilas();
    int columna = m.getColumnas();
	// utiliza para orientar las posiciones
    int sF[8]={-1, -1, 0, 1, 1, 1, 0, -1};
    int sC[8]={0, 1, 1, 1, 0, -1, -1, -1};

    Matriz* mascara = new Matriz(fila, columna); // se cre una matriz

	// inicializa las celdas de la matriz
    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            mascara->setCelda(f, c, 1);
        }
    }

	// recorre utiliza las estructuras de datos vector y matriz para calcular la frecuencia con que son vecinos 2 números
    int frecuencia = 0;
    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            if (m.getCelda(f, c) == n1) {
                if (n1 == n2) {
                    mascara->setCelda(f, c, 0);
                    ++frecuencia;
                }
                for (int v = 0; v < 8; ++v) {
                    if (esPosicionValida(m, f + sF[v], c + sC[v]) && mascara->getCelda(f + sF[v], c + sC[v]) == 1) {
                        if (m.getCelda(f + sF[v], c + sC[v]) == n2) {
                            ++frecuencia;
                        }
                    }
                }
            }
        }
    }
    return frecuencia; // retorna la frecuencia calculada entre 2 números
}

bool Normalizar::esPosicionValida(Matriz& m, int f, int c){ // verifica la validez de la dirección de una celda
    return (f >= 0 && f < m.getFilas() && c >= 0 && c < m.getColumnas()); // retorna un booleano para indicar si la posición es válida
}

Matriz& Normalizar::multiplicarMatriz(Matriz& m, int n) {
    Matriz* multiplicada = new Matriz(n, n); // crea una matriz cuadrada

    int sumatoria;
    for (int f = 0; f < n; ++f) {
        for (int c = 0; c < n; ++c) {
            sumatoria = 0;
            for (int p = 0; p < n; ++p) {
                sumatoria += m.getCelda(p, c) * m.getCelda(f, p); // multiplica una celda de la matriz con su transpuesta
            }
            multiplicada->setCelda(f, c, sumatoria); // va guardando el resultado del producto en las celdas de la matriz "duplicada"
        }
    }

    return* multiplicada; // devuelve la referencia
}

Matriz& Normalizar::crearMatrizNormalizada(Matriz& m, int n){
    Matriz* normalizada = new Matriz(n, n); // declara e inicializa una nueva matriz

    double dato = 0.0; // declara e inicializa la variable local
    for (int f = 0; f < n; ++f) {
        for (int c = 0; c < n; ++c) {
            dato = (double)(2 * (m.getCelda(f, c))) / (m.getCelda(f, f) + m.getCelda(c, c)); // utiliza la fórmula para convertir proporcionalmente los datos entre 0 y 1
            normalizada->setCelda(f, c, dato); // asigna el resultado en la nueva matriz con los valores normalizados
        }
    }

    return* normalizada; // devuelve la referencia
}

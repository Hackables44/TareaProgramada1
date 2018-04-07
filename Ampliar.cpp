
#include "Ampliar.h"

Ampliar::Ampliar() {
}

Ampliar::Ampliar(const Ampliar& orig) {
}

Ampliar::~Ampliar() {
}

Matriz& Ampliar::amplificarMatriz(Matriz& m, int fila, int columna) {

    int tamfila = 2 * fila + 1;
    int tamcolumna = 2 * columna + 1;
    Matriz* matrizAmplificada = new Matriz(tamfila, tamcolumna);

    for (int f = 0; f < tamfila; ++f) {
        for (int c = 0; c < tamcolumna; ++c) {
            matrizAmplificada->setCelda(f, c, 0.1);
        }
    }


    int dato;
    int contfila = 0;
    int contcolumna = 0;
    for (int f = 0; f < tamfila - 1; f += 2) {
        for (int c = 0; c < tamcolumna - 1; c += 2) {
            dato = m.getCelda(contfila, contcolumna);
            matrizAmplificada->setCelda(f + 1, c + 1, dato);
            ++contcolumna;
        }
        contcolumna = 0;
        ++contfila;
    }


    return* matrizAmplificada;
}

Matriz& Ampliar::agrandarMatriz(Matriz& original, int n) {

    Vector vectorElementosMatriz;
    vectorElementosMatriz = original.crearVectorNumDiferentes();
    int t = vectorElementosMatriz.getTamanyo();

    Normalizar normalizar;
    Ampliar ampliar;
    Rellenar rellenar;

    Matriz* p;
    
    Matriz ampliada = original;
    Matriz matrizFrecuencia;
    Matriz matrizMultiplicada;
    Matriz matrizNormalizada;
    Matriz matrizAmplificada;
    Matriz matrizRellenada;

    ampliada.verMatriz();

    for (int d = 0; d < n; ++d) {

        if (d > 0) {

            matrizFrecuencia.~Matriz();
            matrizMultiplicada.~Matriz();
            matrizNormalizada.~Matriz();
            matrizAmplificada.~Matriz();
            matrizRellenada.~Matriz();
        }

        matrizFrecuencia = normalizar.crearMatrizFrecuencia(ampliada, vectorElementosMatriz, t);
        matrizMultiplicada = normalizar.multiplicarMatriz(matrizFrecuencia, t);
        matrizNormalizada = normalizar.crearMatrizNormalizada(matrizMultiplicada, t);
        matrizAmplificada = ampliar.amplificarMatriz(ampliada, ampliada.getFilas(), ampliada.getColumnas());
        matrizRellenada = rellenar.rellenarMatriz(matrizAmplificada, matrizNormalizada, vectorElementosMatriz);

        ampliada.~Matriz();
        
        ampliada = matrizRellenada;
        ampliada.verMatriz();
    }

    matrizFrecuencia.~Matriz();
    matrizMultiplicada.~Matriz();
    matrizNormalizada.~Matriz();
    matrizAmplificada.~Matriz();
    matrizRellenada.~Matriz();
    
    p = &ampliada;
    
    
    return* p;
}
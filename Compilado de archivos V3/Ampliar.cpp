
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

    int cont = 0;

    Normalizar normalizar;
    Ampliar ampliar;
    Rellenar rellenar;

    Matriz* retornar;

    Matriz matrizFrecuencia[n];
    Matriz matrizMultiplicada[n];
    Matriz matrizNormalizada[n];
    Matriz matrizAmplificada[n];
    Matriz matrizRellenada[n];

    original.verMatriz();


    for (int d = 0; d < n; ++d) {


        if (d == 0) {
            matrizFrecuencia[d] = normalizar.crearMatrizFrecuencia(original, vectorElementosMatriz, t);

            matrizMultiplicada[d] = normalizar.multiplicarMatriz(matrizFrecuencia[d], t);
            matrizNormalizada[d] = normalizar.crearMatrizNormalizada(matrizMultiplicada[d], t);
            matrizAmplificada[d] = ampliar.amplificarMatriz(original, original.getFilas(), original.getColumnas());
            matrizRellenada[d] = rellenar.rellenarMatriz(matrizAmplificada[d], matrizNormalizada[d], vectorElementosMatriz);
        } else {
            matrizFrecuencia[d] = normalizar.crearMatrizFrecuencia(matrizRellenada[d - 1], vectorElementosMatriz, t);

            matrizMultiplicada[d] = normalizar.multiplicarMatriz(matrizFrecuencia[d], t);
            matrizNormalizada[d] = normalizar.crearMatrizNormalizada(matrizMultiplicada[d], t);
            matrizAmplificada[d] = ampliar.amplificarMatriz(matrizRellenada[d - 1], matrizRellenada[d - 1].getFilas(), matrizRellenada[d - 1].getColumnas());
            matrizRellenada[d] = rellenar.rellenarMatriz(matrizAmplificada[d], matrizNormalizada[d], vectorElementosMatriz);

            ++cont;
        }


        matrizRellenada[d].verMatriz();
    }


    retornar = &matrizRellenada[cont];


    for (int d = 0; d < n; ++d) {
        matrizFrecuencia[d].~Matriz();
        matrizMultiplicada[d].~Matriz();
        matrizNormalizada[d].~Matriz();
        matrizAmplificada[d].~Matriz();
        
        if(d != cont){
            matrizRellenada[d].~Matriz();
        }
    }



    return* retornar;
}
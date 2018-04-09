
#include "Rellenar.h"

Rellenar::Rellenar() {
}

Rellenar::Rellenar(const Rellenar& orig) {
}

Rellenar::~Rellenar() {
}




//Crea una copia de la matriz con espacios vacios y luego la rellena celda por celda

Matriz& Rellenar::rellenarMatriz(Matriz& mMascara, Matriz& mNormalizada, Vector& vector) {

    double prueba; //PRUEBA


    double dato;
    int fila = mMascara.getFilas();
    int columna = mMascara.getColumnas();
    Matriz* m = new Matriz(fila, columna);

    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            prueba = mMascara.getCelda(f, c); //PRUEBA
            m->setCelda(f, c, mMascara.getCelda(f, c));
        }
    }

    for (int f = 0; f < fila; ++f) {
        for (int c = 0; c < columna; ++c) {
            if (m->getCelda(f, c) == 0.1) {
                dato = mejorVecino(mMascara, mNormalizada, vector, f, c);
                m->setCelda(f, c, dato);
            }
        }
    }

    return* m;
}

//Busca entre todos los vecinos válidos de la celda actual y analiza cual es el vecino mas probable para todos los encontrados
//Luego rellena la celda actual de la matriz con el vecino ganador

int Rellenar::mejorVecino(Matriz& mMascara, Matriz& mNormalizada, Vector& vector, int f, int c) {

    // f y c son la posicion actual de la matriz desde donde se quieren buscar los vecinos
    int sF[8]{-1, -1, 0, 1, 1, 1, 0, -1};
    int sC[8]{0, 1, 1, 1, 0, -1, -1, -1};
    int filaPosicion;
    int registro[vector.getTamanyo()];
    int sum;
    int prueba1 = vector.getTamanyo(); //prueba
    for (int f1 = 0; f1 < vector.getTamanyo(); ++f1) {
        registro[f1] = 0;
    }


    for (int v = 0; v < 8; ++v) {
        if (esPosicionValida(mMascara, f + sF[v], c + sC[v])) {
            if (mMascara.getCelda(f + sF[v], c + sC[v]) != 0.1) {
                filaPosicion = hallarPosicion(vector, mMascara.getCelda(f + sF[v], c + sC[v]));
                sum = registro[filaPosicion];
                sum += 1;
                registro[filaPosicion] = sum;
            }
        }
    }

    double pesoAsociacion = 0.0;
    int mayorVecino;
    int columnaPosicion;
    int soloUno = 0;

    for (int v = 0; v < vector.getTamanyo(); ++v) {
        
        
        if (registro[v] != 0) {
            ++soloUno;
            columnaPosicion = hallarPosicionMayor(mNormalizada, v); //recibe la fila y me da la pocision de la columna

            if (pesoAsociacion < (registro[v] * (mNormalizada.getCelda(v, columnaPosicion)))) {

                pesoAsociacion = (double) (registro[v]*(mNormalizada.getCelda(v, columnaPosicion)));
                mayorVecino = vector.get(columnaPosicion);
            }
        }
    }

    if (soloUno == 1) {
        mayorVecino = vector.get(filaPosicion);
    }



    return mayorVecino;
}


//Busca la posicion en el vector de elementos del número solicitado

int Rellenar::hallarPosicion(Vector& vector, int n) {
    bool seguir = true;
    int cont = 0;

    while (seguir && cont < vector.getTamanyo()) {

        if (vector.get(cont) == n) {
            seguir = false;
        } else {
            ++cont;
        }
    }

    return cont;
}

//Inicializa y devuelve la posicion del elemento mayor

int Rellenar::hallarPosicionMayor(Matriz& mNormalizada, int f) {

    int columna = 0;
    int pos;

    pos = hallarPosicionMayor(mNormalizada, f, columna);

    return pos;
}

//Se llama recursivamente y luego compara en cada caso cual elemento es el mayor

int Rellenar::hallarPosicionMayor(Matriz& mNormalizada, int f, int c) {

    int pos;
    double p1;
    double p2;

    if (c < (mNormalizada.getColumnas() - 1)) {
        pos = hallarPosicionMayor(mNormalizada, f, c + 1);

        if (mNormalizada.getCelda(f, c) < 1) {
            p1 = mNormalizada.getCelda(f, pos);
            p2 = mNormalizada.getCelda(f, c);
            if (mNormalizada.getCelda(f, pos) <= mNormalizada.getCelda(f, c)) {
                pos = c;
            }
        }
    } else {
        if (mNormalizada.getCelda(f, c) < 1) {
            pos = c;
        }
        else{
            pos = c - 1;
        }
    }

    return pos;
}


//verifica si dicha posicion es válida en la matriz

bool Rellenar::esPosicionValida(Matriz& mMascara, int f, int c) {
    return (f >= 0) && (f < mMascara.getFilas()) && (c >= 0) && (c < mMascara.getColumnas());
}





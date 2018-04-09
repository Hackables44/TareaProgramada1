
// Main.cpp		La función principal da inicio al programa

// importa las librerías necesarias par el uso de clases y sus respectivas funciones
#include <fstream> // permite leer flujos de bits (lee byte por byte)
#include <iostream> // permite realizar operaciones de entrada y salida
#include <stdlib.h> // permite el uso de new y delete
#include "Matriz.h" // Incluye la definición de la clase Matriz
#include "Vector.h" // Incluye la definición de la clase Vector
#include "Normalizar.h"
#include "Ampliar.h"
#include "Rellenar.h"
#include <sstream>

using namespace std; // permite utilizar todos los nombres de cualquier librería estándar de C++

int main(int argc, char ** argv) {
    
    cout << "Cantidad de argumentos: " << argc << endl; // imprime en pantalla la cantidad de argumentos ingresados
    // imprimiremos en pantalla los parámetros ingresados
    for (int i = 0; i < argc; ++i) {
        cout << "argumento " << i << ": " << argv[i] << endl;
    } // fin de la estructura iterativa
    // declaramos las variables locales que necesitamos; como el nombre del archivo a extraer bytes y la cantidad de veces a duplicar la matriz
    char * nombre_archivo; // almacenará el nombre del archivo a extraer bytes, que en este caso contiene a la matriz
    int veces_duplicar; // almacenará la cantidad de veces a duplicar la matriz
    // estas variables son para hacer el código más legible
    int filas; // almacenará la cantidad de filas de la matriz
    int columnas; // almacenará la cantidad de columnas de la matriz
    int numero; // almacenará el número recibido de veces a duplicar


    // inicializamos las variables locales
    if (argc > 2) { // si se han ingresado más de 2 parámetros, mínimo 3, tomaremos el 2do (nombre del archivo) y 3er parámetro (veces a duplicar)
        nombre_archivo = argv[1]; // asigna el nombre (o ruta) del archivo a extraer bytes
        veces_duplicar = stoi(argv[2]); // realiza un parsing y asigna la cantidad de veces a duplicar la matriz
    } else { // si se han ingresado menos (menor estricto) de 3 parámetros, signaré valores por defecto
        nombre_archivo = (char *) "matriz.txt"; // asigna el nombre de un archivo por defecto
        veces_duplicar = 2; // asigna un valor de forma predeterminada
    } // fin de la doble condicional

    fstream entrada(nombre_archivo); // creamos una instancia de objeto fstream en la pila
    // aquí las variables locales filas y columnas hacen el código más legible
    // asigna los flujos de bytes
    entrada >> filas; // la primera celda (primer byte) del .txt es el número de filas
    entrada >> columnas; // la primera celda (primer byte) del .txt es el número de filas
    Matriz original(filas, columnas); // creamos una instancia de objeto Matriz en la pila
    // asigna los valores almacenados en el objeto fstream
    for (int f = 0; f < original.getFilas(); ++f) { // recorre las filas de la matriz original
        for (int c = 0; c < original.getColumnas(); ++c) { // recorre las columnas de la matriz original
            entrada >> numero; // recibe el número entero
            original.setCelda(f, c, numero); // va asignando los bytes almacenados por el objeto fstream
        } // fin del for anidado que recorre las columnas
    } // fin del for que recorre las filas
    cout << endl; // deja un espacio en blanco
    //original.verMatriz(); // imprime en pantalla la matriz original

    //Vector vector(filas*columnas);

    
/*
    Vector vectorElementosMatriz;
    vectorElementosMatriz = original.crearVectorNumDiferentes(); // crea el vector que almacena cada elemento diferente del txt

    int t;
    t = vectorElementosMatriz.getTamanyo(); 
    Normalizar normalizar;
    Ampliar ampliar;
    
    Matriz matrizFrecuencia;
    Matriz matrizMultiplicada;
    Matriz matrizNormalizada;
    Matriz matrizAmplificada;

    matrizFrecuencia = normalizar.crearMatrizFrecuencia(original, vectorElementosMatriz, t);
    matrizMultiplicada = normalizar.multiplicarMatriz(matrizFrecuencia, t);
    matrizNormalizada = normalizar.crearMatrizNormalizada(matrizMultiplicada, t);
    matrizAmplificada = ampliar.amplificarMatriz(original, original.getFilas(), original.getColumnas());

    original.verMatriz();
    matrizFrecuencia.verMatriz();
    matrizMultiplicada.verMatriz();
    matrizNormalizada.verMatriz();
    matrizAmplificada.verMatriz();

    
    
    Rellenar rellenar;
    
    Matriz matrizRellenada;

    matrizRellenada = rellenar.rellenarMatriz(matrizAmplificada, matrizNormalizada, vectorElementosMatriz);
    
    matrizRellenada.verMatriz();
    
 */
    
    Vector vectorElementosMatriz;
    vectorElementosMatriz = original.crearVectorNumDiferentes(); // crea el vector que almacena cada elemento diferente del txt

    int t;
    t = vectorElementosMatriz.getTamanyo(); 
    
    Ampliar ampliar;
    
    Matriz matrizAmpliada;
    matrizAmpliada = ampliar.agrandarMatriz(original,2);
    
    
    

    //vector.~Vector();
    // original.~Matriz();
    return 0; // es una buena práctica de programación; indica que el programa ha terminado correctamente
} // fin de la función principal
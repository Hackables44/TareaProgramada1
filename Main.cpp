#include "Matriz.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int Main(int argc, char ** argv){

  cout << "Cantidad de parametros:"<< argc << endl;
  for(int i=0; i<argc; ++i){
    cout << "argumento "<<i<< ": "<< argv[i] <<endl;
  }
  cout << endl;


 int filas;
 int columnas;
 char * nombre;



 if(argc>1){
   nombre = argv[1];
 }
 else {
     nombre = (char *) "datos2.txt";
 }
 //fstream entrada(nombre);
 fstream entrada("datos2.txt");

  entrada >> filas;
  entrada >> columnas;

  Matriz matriz(filas, columnas);

  for(int f = 0;f < filas;++f){
   // matriz[f] = new int [columnas];
    for(int c = 0;c < columnas; ++c){
    //entrada >> matriz[f][c];
    matriz.set(f, c, entrada);
    }
  }
	matriz.salidadTxt();


  return 0;
}

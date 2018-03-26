#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void lectorDeTxt();
void salidaDeTxt();
fstream entrada("datos.txt");
int filas , columnas , **matriz;
 int main(){
   lectorDeTxt();
   salidaDeTxt();
   return 0;
 }

 void lectorDeTxt(){
    entrada >> filas;
    entrada >> columnas;
      matriz = new int *[filas];
    for(int f = 0;f < filas;++f){
      matriz[f] = new int [columnas];
      for(int c = 0;c < columnas; ++c){
      entrada >> matriz[f][c];
      }
    }
 }
 void salidaDeTxt(){
     cout << "SALIDA" << endl;
    for(int f = 0;f<filas;++f){
      for(int c = 0; c<columnas;++c){
        cout << matriz[f][c] << " ";
      }
      delete [] matriz[f];
      cout << endl;
    }
    delete [] matriz;

 }

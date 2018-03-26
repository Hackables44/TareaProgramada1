#include "Matriz.h"


#include<iostream>
using namespace std;

Matriz::Matriz(int filas, int columnas){
   this->filas = filas;
   this->columnas = columnas;

   //int * * matriz;
   matriz = new int *[filas];
     for(int f = 0;f < filas;++f){
       matriz[f] = new int [columnas];
       for(int c = 0;c < columnas; ++c){
        matriz[f][c] = 0;
       }
     }
   }

   void Matriz::set(int i, int j, int valor){
   	if(i >=0 && i < filas && j < columnas){
   		  matriz[i][j] = valor;
   	}
  }

  // void Matriz::lectorDeTxt(){
       //entrada >> filas;
       //entrada >> columnas;
         //matriz = new int *[filas];
       //for(int f = 0;f < filas;++f){
        // matriz[f] = new int [columnas];
         //for(int c = 0;c < columnas; ++c){
         //entrada >> matriz[f][c];
         //}
       //}
    //}

void Matriz::salidadTxt(){
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

#include <iostream>
using namespace std;
int f = 0;
int c = 0;
int n; //length de la matriz
int recursivo();
int recursivo2(int,int,int);
bool esPosicionValida(int,int);

int main(){

  return 0;
}

int recursivo(){
  int frecuencia = recursivo2(f,c,i);//donde i es el numero al que se le quiere sacar la frecuencia
  return frecuencia;
}

int recursivo2(int f, int c,int i){
  int frecuencia = 0;
  int controlador = 0;// no sé si esto será necesario pero no lo pienso de otra forma 
  if(i == m[f][c]){
    ++frecuencia;
  }
switch(controlador){
  case 0 : controlador = 1;
  recursivo2(f-1,c,i);
  break;
  case 1 : controlador = 2;
  recursivo2(f-1,c+1,i);
  break;
  case 2 : controlador = 3;
  recursivo2(f,c+1,i);
  break;
  case 3 : controlador = 4;
  recursivo2(f+1,c+1,i);
  break;
  case 4 : controlador = 5;
  recursivo2(f+1,c,i);
  break;
  case 5 : controlador = 6;
  recursivo2(f+1,c-1,i);
  break;
  case 6 : controlador = 7;
  recursivo2(f,c-1,i);
  break;
  case 7 : //controlador = 0; ???
  recursivo2(fila-1,c-1,i);
  break;
}



  }

  bool esPosicionValida(int f,int c ){
      //return f>0 && f < m.length && c > 0 && c< m[f].length;
  }

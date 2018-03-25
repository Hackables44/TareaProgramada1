#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char ** argv){
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
	   	nombre = (char *) "datos.txt";
	}
	fstream entrada(nombre);
	
	entrada >> filas;
	entrada >> columnas;
	
	int * * m;
	m = new int * [filas];
	for(int f=0; f<filas; ++f){
	   m[f] = new int [columnas];
	   for(int c=0; c<columnas; ++c){
		   entrada >> m[f][c];    
	   }
	}


	for(int f=0; f<filas; ++f){	 
	   for(int c=0; c<columnas; ++c){
		   cout << m[f][c] << " ";    
	   }
	   delete [] m[f];
	   cout << endl;
	}	
	delete [] m;	
}

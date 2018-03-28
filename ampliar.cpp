// Main.cpp		La función main da inicio a la ejecución del programa
#include <iostream> // permite realizar operaciones de entrada y salida
#include <fstream> // permite leer bytes

using namespace std; // permite utilizar todos los nombres de cualquier librería estándar de C++

int main( int argc, char ** argv ){
	// "int argc" es un contador de parámetros automático y "char ** argv" son los parámetros recibidos como entrada ???*
	cout << "Cantidad de parametros: " << argc << endl; // imprime en pantalla la cantidad de parámetros recibidos
	
	for(int i=0; i<argc; ++i){ // imprime los parámetros en pantalla
		cout << "Argumento " << i << ": " << argv[i] << endl;
	} // fin de la estructura iterativa for
	cout << endl; // deja una línea en blanco
	
	// declaración de variables
	char * nombre_archivo; // almacenará el nombre (o ruta) del archivo al que extraerá bytes
	int veces_duplicar; // almacenará la cantidad de veces a duplicar
	int filas; // almacenará las filas de la matriz
	int columnas; // almacenará las columnas de la matriz
	
	// inicialización de variables
	if( argc > 2 ){ // si hay más de 2 argumentos(nombre del programa, nombre del archivo y número de veces a duplicar la matriz)
		// asigna el segundo y tercer parámetro
		nombre_archivo = argv[1]; // almacena el nombre del archivo a extraer bytes
		veces_duplicar = stoi(argv[2]); // almacena la cantidad de veces a duplicar el archivo 
	}
	else{ // si se ingresan menos de 3 parámetros, se asignarán valores predeterminados
		nombre_archivo = (char *) "datos.txt"; // guarda el nombre de un archivo por defecto;
		veces_duplicar = 2; // asigna un valor por defecto
	} // fin de la doble condicional
	
	// Permite visualizar el nombre del archivo y las veces a duplicar
	cout << "Nombre del archivo: " << nombre_archivo << endl << "Veces a duplicar matriz: " << veces_duplicar << endl;
	
	fstream entrada(nombre_archivo); // crea un objeto fstream llamado entrada el cual extrae los bytes del archivo indicado
	
	// los primeros dos bytes (celdas) contienen las dimensiones de la matriz
	entrada >> filas; // almacena la cantidad de filas
	entrada >> columnas; // almacena la cantidad de columnas
	
	// crea la matriz por medio de punteros (crea un vector de vectores); es un vector de punteros a vectores de números
	int * * m; // será puntero de puntero
	m = new int * [filas];// asigno un vector de punteros
	for(int f=0; f<filas; ++f){ // recorre el vector que representa la primera celda de cada fila
		m[f]=new int[columnas]; // a cada puntero le asigno la referencia a la primera celda de un vector de enteros; con lo que se va creando la segunda dimensión
		for(int c=0; c<columnas; ++c){ // conforme crea la segunda dimesión; asimismo recorre las celdas para asignar valores
			entrada >> m[f][c]; // asigna los bytes (en este caso números) restantes
		} // termina de recorrer la segunda dimensión
	} // fin de la estructura repetitiva
	
	int filas2=filas*2+1;
	int columnas2=columnas*2+1;
	int * * m2; // crea una segunda matriz, que será el doble de la primera
	m = new int * [filas2]; // crea la primera dimensión duplicada
	for(int f=0; f<filas2; ++f){ // recorre el vector de punteros
		m[f] = new int[columnas2]; // va creando la segunda dimensión duplicada
		for(int c=0; c<columnas2; ++c){ // recorre las columnas
			m2[f][c] = 0; // inicializa las celdas de la matriz
		} // fin del for anidado
	} // fin de la estructura iteratica for
	
	// recorre la matriz m y asigna esos valores en la matriz m2
	for(int f=0; f<filas; ++f){ // recorre las filas
		for(int c=0; c<columnas; ++c){ // recorre las columnas
			m2[f*2+1][c*2+1] = m[f][c]; // asigna los valores de la matriz original a una matriz ampliada
		} // fin de la estructura iterativa for anidado
	} // fin de la estructura iterativa for
	
	// imprime los valores de la matriz ampliada
	for(int f=0; f<filas2; ++f){
		for(int c=0; c<columnas2; ++c){
			cout << m2[f][c];
		}
		delete [] m[f];
	}
	delete []m;
	
	// recorre la matriz mientras elimina los vectores
	for(int f=0; f<filas; ++f){ // recorre las filas de la matriz, la primera dimesión
		for(int c=0; c<columnas; ++c){ // recorre las columnas; la segunda dimensión
			cout << m[f][c]; // imprime el valor en las celdas
		}
		delete [] m[f]; // elimina el vector de números en la fila indicada
	}
	delete [] m; // elimina el vector de punteros
	
	return 0; // es una buena práctica de programación, indica que el programa ha terminado correctamente
} // fin de la función principal

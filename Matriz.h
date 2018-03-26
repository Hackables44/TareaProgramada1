#ifndef _MATRIZG4
#define _MATRIZG4
class Matriz {
   private:
     int filas;
     int columnas;
    char * nombre;
    int * * matriz;

   public:
    Matriz(int, int);
	  void set(int, int, int);
    void salidadTxt();
    //~Matriz();
};
#endif

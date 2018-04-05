//se tienen que recivir estos parametros para poder trabajar, mi idea era usar la longitud del vector para saber cuantas varaibles de contador de frecuencia hacer
void rellenarMatriz(Matriz& original, int lengthVector, Matriz& ampliada, Matriz& frecuencia){


int fila = ampliada.getFilas();
int columna = ampliada.getColumnas();
int sF[8]{-1, -1, 0, 1, 1, 1, 0, -1};
int sC[8]{0, 1, 1, 1, 0, -1, -1, -1};
//estas 2 son para ir arriba abajo.. en la original y de frecuencia para hacer los calculos
int sF2[4]{-1,0,1,0};
int sC2[4]{0,1,0,-1};
Matriz* mascara = new Matriz(fila, columna);

for (int f = 0; f < fila; ++f) {
    for (int c = 0; c < columna; ++c) {
        mascara->setCelda(f, c, 0);
    }
}



for (int f = 0; f < fila; ++f) {

    for (int c = 0; c < columna; ++c) {

        if (ampliada.getCelda(f, c) == -1) {

            for (int v = 0; v < 8; ++v) {

                if (esPosicionValida(ampliada, f + sF[v], c + sC[v]) && mascara->getCelda(f + sF[v], c + sC[v]) == 0) {

                    if (ampliada.getCelda(f + sF[v], c + sC[v]) != -1) {
                        //llamamos a su original y vemos que esta arriba,abajo..

                        //Y por ende a su asociativa (teniendo en cuenta que haya que llevar la cuenta de las sumas)
                        //llenar de if else para determinar cual es el mayor y pasandolo por un vector del tamaño de las filas de la matriz de frecuencia
                    }
                }
            }
          }
            else{
              //pasa el valor automaticamente a la máscara
                 mascara.setCelda(f,c,ampliada.getCelda(f,c));
            }


        }
        //reiniciar el valor de todos los contadores
    }
}

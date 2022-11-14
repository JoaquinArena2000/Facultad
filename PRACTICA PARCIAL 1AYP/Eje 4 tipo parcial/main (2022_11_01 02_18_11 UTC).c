#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Ejercicio 4
En una matriz de 4 X 3 se carga con números. Se solicita sumar los valores
de su columna y guardarlos en un vector. Luego mostrar los resultado.
*/
#define f 4
#define c 3
void cargar_matriz(int matriz[][c] );
void mostrar_matriz(int matriz[][c] );
void suma_col (int matriz[][c], int vector[c] );
void mostrar_vector(int vector[c]);

int main()
{
    int matriz[f][c];
    int vector[c];
    srand(time(NULL));
    cargar_matriz(matriz);
    mostrar_matriz(matriz);
    suma_col(matriz, vector);
    mostrar_vector(vector);

    return 0;
}
void cargar_matriz(int matriz[][c])
{
    int i , j ;
    srand(time(NULL));
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            matriz[i][j]=  rand()%10 ;
        }
    }
}
void mostrar_matriz(int matriz[][c])
{
    int i , j ;
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void suma_col(int matriz[][c],  int vector[c])
{
int i , j , suma=0 ;


         for (j=0;j<c;j++)
         {      suma=0;

               for (i=0;i<f;i++)
               {
                   suma+=matriz[i][j];
                   vector[j]=suma;

               }

         }
 return 0;
}
void mostrar_vector(int vector[c])
{
int i ;
    printf("\nMOSTRAMOS LA SUMA DE LAS COLUMNAS EN UN VECTOR\n ");
     for(i=0;i<c;i++)
    printf("%d ", vector[i]);


}

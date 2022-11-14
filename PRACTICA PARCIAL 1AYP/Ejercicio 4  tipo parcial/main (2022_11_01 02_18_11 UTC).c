#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define f 4
#define c 3
void cargar_matriz (int matriz[][c]);
void mostrar_matriz (int matriz[][c]);
void sumar_columnas(int matriz[][c]);
int main()
{
    int matriz[f][c];
    srand(time(NULL));
    cargar_matriz(matriz);
    mostrar_matriz(matriz);
    sumar_columnas(matriz);
    return 0;
}
void cargar_matriz(int matriz[][c])
{

int i  , j ;
srand(time(NULL));
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
             matriz[i][j]= rand()% + 10;
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
                printf("\t%d", matriz[i][j]);
            }
            printf("\n");
        }
}
void sumar_columnas(int matriz[][c])
{
    int i ,  j ,sumacol=0, vector[i];
         for (j=0;j<c;j++)
         {
             sumacol=0;
             for (i=0;i<c;i++)
             {
                sumacol= sumacol+ matriz[i][j
                ];


             }sumacol=vector[i];

printf("\nLA SUMA DE LAS COLUMNAS ES %d ",vector[i]);
         }

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Ejercicio 2
Si tenemos la siguiente matriz de 5 X 5. Se pide mostrar La misma matriz del ejercicio anterior, pero ahora debes mostrar los valores
del sector marcado con amarillo, y decir cuantos datos contiene ese sector
*/
#define f 5
#define c 5
void cargar_matriz(int matriz[][c]);
void mostrar_matriz(int matriz[][c]);
void nueva_matriz (int matriz[][c]);


int main()
{
    int matriz[f][c];
     srand(time(NULL));
   cargar_matriz(matriz);
   mostrar_matriz(matriz);
   nueva_matriz(matriz);


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
                printf(" %d " , matriz[i][j]);
             }
             printf("\n");
         }
}
void nueva_matriz(int matriz[][c])
{
    int i , j,contador=0; ;
    printf ("\n\n A CONTINUACION MOSTRAREMOS LA MATRIZ TRIANGULITO");
         for (i=0;i<f;i++)
         { printf ("\n\n");
             for (j=0;j<c;j++)
            {
             if((i<=j )&& (i+j <= c-1))

               {
                printf ("\t%d", matriz[i][j]);
                contador++;

               }
             else
                printf ("\t-");


            }
        }
        printf("\n\n Los datos del nuevo sector son %d ", contador );
}





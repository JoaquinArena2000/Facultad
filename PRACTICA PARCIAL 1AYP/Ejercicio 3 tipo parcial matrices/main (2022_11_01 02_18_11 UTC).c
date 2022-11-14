#include <stdio.h>
#include <stdlib.h>
/*Seguimos con la misma matriz, ahora debemos cambiar el valor que tiene
la matriz en el sector sombreado.
Vamos a cambiar los datos de la siguiente forma.
Si es número es par colocamos un 1 (uno), si es impar colocamos un 0 (cero)
*/

#define f 6
#define c 6
void cargar_matriz(int matriz[][c]);
void mostrar_matriz(int matriz[][c]);
void matriz_nueva(int matriz [][c]);

int main()
{
    int matriz[f][c];
     srand(time(NULL));
   cargar_matriz(matriz);
   mostrar_matriz(matriz);
   matriz_nueva(matriz);

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
                printf("\t%d" , matriz[i][j]);
             }
             printf("\n");
         }
}
void matriz_nueva(int matriz[][c])
{
    int i , j ;
        printf (" \n                NUEVA MATRIZ 0 1           \n");
        for (i=0;i<f;i++)
        {
            printf("\n");
            for (j=0;j<c;j++)
            {
                if ((i+j)>= (c-1))
                {
                     if (matriz[i][j]% 2==0)
                     {
                        matriz[i][j]=1;
                        printf("\t%d", matriz[i][j]);
                     }

                     else
                     {
                         matriz[i][j]=0;
                        printf ("\t%d", matriz[i][j]);
                     }

                }
                else
                    printf ("\t-");
            }

        }
}

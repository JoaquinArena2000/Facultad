#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Ejercicio 1
Si tenemos la siguiente matriz de 5 X 5. Se pide mostrar los números pares
y la suma de lo mismo, del sector marcado con amarillo.
*/
#define f 6
#define c 6
void cargar_matriz(int matriz[][c]);
void mostrar_matriz(int matriz[][c]);
void numeros_pares (int matriz[][c]);
void suma_pares (int matriz[][c]);
int main()
{
    int matriz[f][c];
     srand(time(NULL));
   cargar_matriz(matriz);
   mostrar_matriz(matriz);
   numeros_pares(matriz);
   suma_pares(matriz);
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
void numeros_pares(int matriz[][c])
{
    int i , j ;
    printf ("\n NUMEROS PARES DIAGONAL SUPERIOR : ");
        for (i=0;i<f;i++)
        {
            printf("\n");
            for (j=0;j<c;j++)
            {
                if (i<=j)
                {
                     if (matriz[i][j]% 2==0)
                        printf("\t%d", matriz[i][j]);
                     else
                    printf ("\t-");
                }
                else
                    printf ("\t-");
            }

        }
}
void suma_pares(int matriz[][c])
{
    int i , j , sumapar=0;
        for (i=0;i<f;i++)
        {
            for (j=0;j<c;j++)
            {
                if (i<=j)
                    if(matriz[i][j]%2==0)
                {
                    sumapar+=matriz[i][j];
                }

            }
        }
        printf ("\nLA SUMA DE LOS NU7MEROS PARES ES: %d ", sumapar );
}

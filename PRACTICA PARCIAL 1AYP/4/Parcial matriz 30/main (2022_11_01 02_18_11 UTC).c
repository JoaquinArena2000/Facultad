#include <stdio.h>
#include <stdlib.h>

/*
Ejercicio de Matriz

En una matriz de 5 X 5 tenemos cargado números aleatorios. • El color azul (parte superior de la contradiagonal) •
El color gris (parte de la contradiagonal) •
El color rosa (parte inferior de la contradiagonalConsigna técnica obligatoria a cumplir

1.      Utilizando funciones cargar los datos a la matriz.

2.      La sumatoria de todos los números pares que pertenecen a la diagonal principal

3.      Mostrar por pantalla los números que pertenecen a la diagonal principal
*/
#define f 5
#define c 5
void cargar_matriz(int matriz[][c]);
void mostrar_matriz(int matriz[][c]);
void mostrar_diagonal_princial(int matriz[][c]);
void sumatoria_par(int matriz [][c]);
int main()
{
    int matriz[f][c];
     srand(time(NULL));
   cargar_matriz(matriz);
   mostrar_matriz(matriz);
   mostrar_diagonal_princial(matriz);
   sumatoria_par(matriz);

    return 0;
}
void cargar_matriz(int matriz[][c]) //Utilizando funciones cargar los datos a la matriz.
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
void mostrar_diagonal_princial(int matriz[][c])
{
    int i  ,  j ;
    printf ("\nLA DIAGONAL PRINCIPAL QUEDO DE ESTA MANERA \n");
            for (i=0;i<f;i++)
            {
                printf("\n");
                for (j=0;j<c;j++)
                {
                    if (i==j)
                        printf("\t%d", matriz[i][j]);


                    else
                        printf ("\t-");
                }

            }
}
void sumatoria_par(int matriz [][c])// La sumatoria de todos los números pares que pertenecen a la diagonal principal
{
    int i  , j ;
    int suma_par=0;
        printf ("\nA CONTINUACION MOSTRAMOS LA SUMATORIA DE LOS NUMEROS PARES DE LA DIAGONAL PRINCIPAL");
        for (i=0;i<f;i++)
        {
            printf("\n");
            for (j=0;j<c;j++)
            {
                if (i==j)
                {
                     if (matriz[i][j]% 2==0)
                      suma_par+=matriz[i][j];
                }

            }

        }
        printf ("\nLA SUMA DE LOS NUMEROS PARES ES: %d ", suma_par );
}

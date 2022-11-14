#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Ejercicio de Estructura:

Una empresa transportadora de mercader�a le solicita a uds.
 La realizaci�n de un sistema sobre el recorrido de sus camiones. Para esto le pide:

Realizar la carga en un vector estructura la siguiente informaci�n

�         N�mero de cami�n

�         Apellido del chofer

�         Kil�metros que recorri�

La empresa les solicita realizar lo siguiente:

   Cargar en una funci�n, un vector estructura con los datos. Considerar que el m�ximo es 25 camiones.

    Luego en otra funci�n necesitamos saber el n�mero de cami�n y el apellido del chofer que realizo el mayor recorrido

�. Si se sabe que el valor del kil�metro es de 210$. Mostrar por pantalla cuanto cobrar�a cada camionero.
*/
#define n 25
typedef struct
{
    int numero_camion;
    char apeliido_chofer[50];
    int cargar_kilometro;
}REGISTRO ;
int cargar_datos(REGISTRO camionero[], int tam );
void mostrar_datos ( REGISTRO camionero [] ,int fin_carga);
void buscar_mostrar_mayorreco ( REGISTRO camionero[], int fin_carga  );
void mostrar_sueldo(REGISTRO camionero[] ,int fin_carga);
int main()
{
    REGISTRO camionero[n];
    int fin_carga;
    fin_carga=cargar_datos(camionero , n);
    mostrar_datos(camionero, fin_carga);
    buscar_mostrar_mayorreco(camionero , fin_carga);
    mostrar_sueldo(camionero ,fin_carga);
    copia();

    return 0;
}
int cargar_datos( REGISTRO camionero[], int tam)
{
     int i=0;
     char sino;

    do
    {
            printf("\n\n Ingrese los datos de los camioneros : ");

            printf("\n\n NUMERO DEl CAMION : ");
            scanf("%d", &camionero[i].numero_camion);

            printf("\n  APELLIDO DEL CHOFER :  ");
            fflush(stdin);
            gets(camionero[i].apeliido_chofer);


            printf("\nKILOMETROS RECORRIDOS : ");
            scanf("%d", &camionero[i].cargar_kilometro);


            printf("\n\n Desea cargar  datos de mas camioneros(s/n) :  ");
            fflush(stdin);
            scanf("%c", &sino);
            i++; //para controlar la posicion
            if (i >= n)
                i=0;

    }while (sino != 'n');

    return i;
}
void mostrar_datos ( REGISTRO camionero [] ,int fin_carga)
{
    int i;
        printf("\n Los datos cargados fueron: \n");
        printf("\n  Nro de camion: \t  Apellido: \t Km recorrido:  ");
            for(i=0; i<fin_carga;i++)
                printf("\n %d    \t\t%s     \t\t\t%d ",camionero[i].numero_camion ,camionero[i].apeliido_chofer , camionero[i].cargar_kilometro);
}
void buscar_mostrar_mayorreco(REGISTRO camionero[] , int fin_carga)
{
    int i=0;
    int mayor_reco=0;
    char apellido;
    int nro_camion=0;
    char destino[50];
    int indice_mayor=0;
         for (i=0;i<fin_carga;i++)
         {
            /* if (i==0)
             {mayor_reco=camionero[i].cargar_kilometro;
                nro_camion=camionero[i].numero_camion;
             }
             */


             if(camionero[indice_mayor].cargar_kilometro<=camionero[i].cargar_kilometro)
             {
                 //mayor_reco=camionero[i].cargar_kilometro;

                 //nro_camion=camionero[i].numero_camion;
                 strcpy ( destino, camionero[i].apeliido_chofer);
                 indice_mayor=i;
             }

         }





         printf ("\n\nEL MAYOR RECORRIDO LO HIZO EL CAMION NRO %d DE APELLIDO %s CON UN TOTAL DE %d KM RECORRIDOS" ,camionero[indice_mayor].numero_camion, );

}
void mostrar_sueldo(REGISTRO camionero[] ,int fin_carga)//Si se sabe que el valor del kil�metro es de 210$. Mostrar por pantalla cuanto cobrar�a cada camionero.
{
    int i=0 ;

        printf("\n  Nro de camion: \tApellido: \t Km recorrido: \tgano $ ");

          for(i=0; i<fin_carga;i++)
          {
              printf("\n %d        \t \t%s  \t\t\t%d  \t\t%d $ ",camionero[i].numero_camion ,camionero[i].apeliido_chofer , camionero[i].cargar_kilometro , camionero[i].cargar_kilometro * 210);
          }
          printf("\n\nACLARACION ---se sabe que el valor de 1 kil�metro es de 210$------");
}
void copia()
{
    char texto[] = "este es un curso de C.";
	char destino[50];

	strcpy( destino, texto );
	printf( "\n\nValor final: %s\n", destino );
}


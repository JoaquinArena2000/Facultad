#include <stdio.h>
#include <stdlib.h>
/*La empresa EDENOR guardaen un vector estructura la siguiente información
Nro de cliente
Categoria
Kilowats
La categoria puede ser C – casa de familia
 E – Empresas
Se solicita que dado un número de cliente muestre la información del mismo.
Finalizar esta información cuando el usuario lo desee.
Una vez finalizada mostar el promedio de kilowats por categoria. Quiere decir mostrar el
promedio de la casa de familia(todas) y el promedio de las empresas (todas)
*/
#define n 10
typedef struct
{
    int nro_cliente ;
    int  kilowats;
    char categoria ;
}REGISTRO ;
int cargar_registro (REGISTRO Edenor[], int tam );
void mostrar_registro(REGISTRO Edenor[] , int fin );
void buscar_en_registro(REGISTRO Edenor[], int fin);
void mostrar_promedio_total(REGISTRO Edenor[] , int fin);

int main()
{
    REGISTRO Edenor [n];
    int fin;
    fin=cargar_registro(Edenor, n);
    mostrar_registro(Edenor, fin);
    buscar_en_registro(Edenor, fin);
    mostrar_promedio_total(Edenor, fin);
    return 0;
}
int cargar_registro(REGISTRO Edenor[], int tam)
{
    int i=0;
    char sino;
    do
    {
         printf ("\nINGRESE LOS DATOS\n\n");
         printf ("\nINGRESE EL NUMERO DE CLIENTE : ");
         scanf ("%d", &Edenor[i].nro_cliente);

         printf("\nINGRESE LA CATEGORIA casa /empresa (c, e) : ");
         fflush(stdin);
         scanf("%c", &Edenor[i].categoria);

         printf("\nINGRESE LOS KILOWATS : ");
         scanf("%d", &Edenor[i].kilowats);


         printf ("\nDESEAS CARGAR MAS DATOS ? s/n : ");
         fflush(stdin);
         scanf("%c", &sino);
         i++; //para controlar la posicion
            if (i >= n)
                i=0;

    }while(sino!=  'n');

    return i ;
}
void mostrar_registro(REGISTRO Edenor[], int fin)
{
    int i;
        printf ("\n ----EL REGISTRO SE CARGO CORRECTAMENTE ----\n\n");

        printf("\n NUMERO DE CLIENTE \t CATEGORIA \t KILOWATS ");

        for (i=0;i<fin;i++)
        {
            printf("\n %d       \t\t%c \t\t\t%d ", Edenor[i].nro_cliente, Edenor[i].categoria, Edenor[i].kilowats);
        }
}
void buscar_en_registro(REGISTRO Edenor[], int fin)//Se solicita que dado un número de cliente muestre la información del mismo.
{
    int i=0;
    char sino;
    int codigo=0;

    do
    {
        printf("\n\nINGRESE EL NUMERO DE CLIENTE A BUSCAR: ");
        scanf("%d", &codigo);


        for(i=0; i< fin; i++)
        {
        if (codigo == Edenor[i].nro_cliente )

            printf("\n NRO DE CLEINTE : %d -CATEGORIA : [%c] -KILOWATS : %d\n",Edenor[i].nro_cliente,  Edenor[i].categoria , Edenor[i].kilowats);


        }
           printf("\n Desea ingresar otro numero de cliente? si-no:  ");
            fflush(stdin);
            scanf("%c", &sino);


    }while(sino!='n' );




}
void mostrar_promedio_total (REGISTRO Edenor[] , int fin)//Una vez finalizada mostar el promedio de kilowats por categoria. Quiere decir mostrar el
//promedio de la casa de familia(todas) y el promedio de las empresas (todas)
{
    int i=0 ;
    float acumC=0;
    float contadorC=0;
    float acumE=0;
    float contadorE=0;
    float promedioc=0;
    float promedioe=0;
        printf("\nA CONTINUACION MOSTRAREMOS EL PROMEDIO TOTAL POR CATEGORIA\n\n");
        for (i=0;i<fin;i++)
        {
            if (Edenor[i].categoria == 'c'||Edenor[i].categoria== 'C' )
            {
                acumC+=Edenor[i].kilowats;
                contadorC++;
            }
            else
                if ( Edenor[i].categoria =='E' || Edenor[i].categoria=='E')
                {
                    acumE+=Edenor[i].kilowats;
                    contadorE++;
                }

        }
        promedioc=acumC/contadorC;
        promedioe=acumE/contadorE;
        printf("EL PROMEDIO DE KILOWATS DE LAS CASAS ES : %.2f \n\n ",promedioc );
        printf("EL PROMEDIO DE KILOWATS DE LAS EMPRESAS ES DE : %.2f ", promedioe);
}



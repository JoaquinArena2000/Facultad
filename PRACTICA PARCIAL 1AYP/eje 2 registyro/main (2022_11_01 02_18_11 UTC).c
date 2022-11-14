#include <stdio.h>
#include <stdlib.h>
/*Una empresa registra en un vector estructura los datos de sus empleados
Legajo campo númerico
Nombre campo char
Apellido campo char
Categoria campo char
Horas trabajadas campo numérico
Las categorias son dos
O- obrero y ganan por hora $2500
 J – Jefe y ganan por hora $5600
Se pide cargar datos de 10 empleados.
Luego solicitar un número de legajo y calcular el sueldo del empleado.
Mostrar esta información hasta que el usuario decide finalizar
*/
#define n 10
  typedef struct
  {
      int legajo;
      char nomyape[50];
      char categoria  ;
      int horas_trabajadas ;
  } REGISTRO ;

  int cargar_datos (REGISTRO  Empleado[], int tam);//va int xq eso me define hasta donde cargo
  void mostrar_datos ( REGISTRO  Empleado [] ,int fin);
  void calcular_sueldo ( REGISTRO  Empleado[], int fin   );

int main()
{
    REGISTRO Empleado[n];

    int fin;


    fin=cargar_datos(Empleado,  n);//para no cargar 50 posiciones
    mostrar_datos(Empleado, fin);
    calcular_sueldo(Empleado, fin);


    return 0;
}
int cargar_datos( REGISTRO Empleado[], int tam)
{
     int i=0;
    char sino;

    do
    {
            printf("\n\n Ingrese los datos de los empleados : ");

            printf("\n\n NUMERO DE LEGAJO : ");
            scanf("%d", &Empleado[i].legajo);

            printf("\n NOMBRE Y APELLIDO :  ");
            fflush(stdin);
            gets(Empleado[i].nomyape);

            printf("\n RANGO DE LA PERSONA operario  O jefe J :") ;
            fflush(stdin);
            scanf ("%c", &Empleado[i].categoria);

            printf("\nCANTIDAD DE HORAS TRABAJADAS : ");
            scanf("%d", &Empleado[i].horas_trabajadas);


            printf("\n\n Desea cargar  datos de mas empleados (s/n) :  ");
            fflush(stdin);
            scanf("%c", &sino);
            i++; //para controlar la posicion
            if (i >= n)
                i=0;

    }while (sino != 'n');

    return i;
}
void mostrar_datos( REGISTRO Empleado[] , int fin)
{
     int i;
        printf("\n Los empleados cargados fueron: \n");
        printf("\n Legajo Nro: \t Nombre y Apellido: \tCategoria: \tHS: ");
            for(i=0; i<fin;i++)
                printf("\n %d  \t\t%s \t\t\t%c \t\t\%d",Empleado[i].legajo,Empleado[i].nomyape, Empleado[i].categoria, Empleado[i].horas_trabajadas);


}
void calcular_sueldo(REGISTRO Empleado[], int fin ) //Luego solicitar un número de legajo y calcular el sueldo del empleado.
{
    int i=0;

    int legajo_solicitado;
    char sino;


    do
    {
        printf("\n INGRESE EL NUMERO DE LEGAJO A BUSCAR : ");
         scanf("%d",&legajo_solicitado);

             for (i=0;i<fin;i++)
             {
                 if( legajo_solicitado == Empleado[i].legajo)
                 {
                         if (Empleado[i].categoria == 'o' || Empleado[i].categoria == 'O')
                                    printf("EL SUELDO DE LA CATEGORIA %c es %d" , Empleado[i].categoria, Empleado[i].horas_trabajadas*2500);


                         else
                            if (Empleado[i].categoria == 'j'|| Empleado[i].categoria== 'J' )
                                    printf("EL SUELDO DE LA CATEGORTIA %c es %d", Empleado[i].categoria, Empleado[i].horas_trabajadas*5600);
                 }


             }
             printf("\n\nDESEAS SEGUIR BUSCANDO? : ");
             fflush(stdin);
             scanf("%c",  &sino);
    }while (sino!='n');


}

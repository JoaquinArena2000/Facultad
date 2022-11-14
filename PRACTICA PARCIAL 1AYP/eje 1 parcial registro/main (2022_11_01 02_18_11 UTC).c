/*Cargar un vector estructura de 20 posiciones.
Código de producto usamos nros aleatorios que varíen entre 1 y el 100
Descripción del producto
Precio
Considerar que no es necesario completar el vector de 20 posiciones.
Luego solicitar por pantalla el codigo del producto y mostrar el precio del mismo.*/

#include <stdio.h>
#include <stdlib.h>

#include<time.h>
#include<string.h>
#define n 20
typedef struct
{
    int Codigo_Produto;
    char Descripcion_Producto[50];
    int Precio_Producto;

}REGISTRO;

int Cargar_Producto(REGISTRO producto[], int Pos);
void Mostrar_producto(REGISTRO producto[],int fin_carga);
void Buscar_producto(REGISTRO producto[], int fin_carga);

int main()
{
    REGISTRO producto [n];
    int i;
	int fin_carga=0;
	srand(time(NULL));
	fin_carga= Cargar_Producto(producto, n);
	Mostrar_producto(producto, fin_carga);

	Buscar_producto(producto, fin_carga);
	return 0;
}

int Cargar_Producto(REGISTRO producto[], int Pos)

{
    int i;
    char SINO;
         for(i=0:i<pos;i++)
    {
        printf("\n El codigo del Producto es: ");
        producto[i].Codigo_Produto= 1+rand()%100;
        printf("%d\n",producto[i].Codigo_Produto);

        printf("\nIngrese descripcion del Producto: ");
		fflush(stdin);
		gets(producto[i].Descripcion_Producto);

        printf("\nIngrese el precio del producto: ");
		scanf("%d", &producto[i].Precio_Producto);


        printf("\n\n Desea ingresar otro Producto? (s/n)  ");
        fflush(stdin);
        scanf("%c",&SINO);
        if (SINO == 'n' || SINO=='N')
            return i+1;

    }

    return i ;
}
void Mostrar_producto(REGISTRO producto[],int fin_carga)
{
    int i;
    system("cls");
	printf("Codigo de producto\t Descripcion\tPrecio\n\n\n");
	for ( i = 0; i < fin_carga ; i++)
	{
		printf("\n %d \t\t\t  %s             %d",producto[i].Codigo_Produto,producto[i].Descripcion_Producto, producto[i].Precio_Producto);

	}
	printf("\n\n\n");
}
void Buscar_producto(REGISTRO producto[], int fin_carga)
{
    int i=0;
    char sino;
    int codigo=0;

    do
    {
    printf("INGRESE EL CODIGO A BUSCAR: \n");
    scanf("%d", & codigo);
    for(i=0; i< fin_carga; i++)
    {
    if (codigo== producto[i].Codigo_Produto )
        {
        printf("\n el precio del producto [%s] es: $ %d\n",producto[i].Descripcion_Producto, producto[i].Precio_Producto);
        }


    }
        printf("\n Desea ingresar otro codigo? si-no:  ");
        fflush(stdin);
        scanf("%c", &sino);


    }while(sino =='s' || sino == 'S' );

}

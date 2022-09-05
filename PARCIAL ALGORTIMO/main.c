#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*El supermercado “EL CHIVO” saben que estudian Algoritmo y Programación en la UNPAZ , entonces le solicitan un programade la siguiente forma:

Utilizando un menú que tiene la siguientes opciones

·         Alta de producto: Graba en el archivo “Producto.bin” los nuevos productos que ingresan al supermercado. Este archivo tiene la siguiente estructura

                                             Código de Producto

                                             Descripción de producto

                                             Precio del Producto

                                             Cantidad de Producto

·         Modificar Producto: Utilizando búsqueda binaria, se ingresa el Código del producto a modificar.
Si se encuentra ese código, permitir cambiar la descripción, el precio y la cantidad.
Si no se encuentra ese código del producto enviar el mensaje “Código No Encontrado”

·         Listar Todos los productos que tiene el supermercado ordenado por Código de Producto


*/
#define MAX 50

typedef struct
{
    int codigo;
    char descripcion[10];
    float precio;
    int cantidad;

} tproducto;

int  miMenu();
int altaArchivo();
int cargarArchivo(tproducto[], int);
int ya_existe_Codigo(tproducto[], int );
void modificar(tproducto[],int);
void ordenarcodigo(tproducto[],int);
int busquedabinario(tproducto[],int,int);
void listar(tproducto[],int);

int main()
{
    tproducto tp[MAX];
    int cant=0;
    int opcion;
    do{
    opcion=miMenu();
    switch (opcion)
    {
    case 1:
        {
            if (altaArchivo()==-1) return -1;
            break;
        }
    case 2:
        {
            cant=cargarArchivo(tp,cant);
            ordenarcodigo(tp,cant);
            modificar(tp,cant);
            break;
        }

    case 3:·  // Listar Todos los productos que tiene el supermercado ordenado por Código de Producto

        {
        cant=cargarArchivo(tp,cant);
        ordenarcodigo(tp,cant);
        listar(tp,cant);
        }

        break;
    case 9:
        break;
    default:
        {
            printf("error de ingreso");
            break;
        }
    }
}while (opcion != '9' || opcion =='1' || opcion=='2' ||	opcion=='3');//valido que la opcion no se salga del rango
    return 0;
}

int miMenu()
{
    int miOpcion;
printf("__________________________________________________________\n\n");

    printf (" SEGUNDO PARCIAL ALGORITMOS Y PROGRAMACION  LGTI\n");

    printf (" ALUMNO: JOACO  / DNI: 000000000\n");
printf("__________________________________________________________\n\n\n");


    printf("1-crear el archivo productos\n");
    printf("2- Modificar productos\n");
    printf("3-Listar ordenado por codigo los productos \n");

    printf("6-Salir\n");
    scanf("%d",&miOpcion);
    return miOpcion;
}
int  altaArchivo()
{
    FILE *archivo;
    tproducto  Tproducto;
    int bandera_stock=0;
    int bandera_precio=0;
    char sino;
    archivo=fopen("Producto.bin","ab");
    if(archivo== NULL)
        return -1;

    do{
    system("cls");
    printf("Alta de productos");
    printf("\n==================");

    do{
    printf("\n\n\n El codigo del producto ; ");
    printf("%d", Tproducto.codigo);
   ya_existe_Codigo(tp ,cant);// esta funcion me devuelve el resultado de la bandera
    }while (bandera==1);



    printf("\nIngrese la descripcion  ");
    fflush(stdin);
    gets(Tproducto.descripcion);


    do{
    printf("\nIngrese el precio  ");
    fflush(stdin);
    scanf("%f",&Tproducto.precio);
    bandera_precio=0;
     if (tproducto.precio<0)//valido que el alta de precio sea mayor a 0
        bandera_precio=1;
    }while (bandera_precio==1);



    do{
    printf("\n Ingrese la cantidad ");
    scanf("%d",&Tproducto.cantidad);
     bandera_stock=0
     if(tproducto.cantidad<0 )//valido que el alta de la cantidad sea mayor a 0
        bandera_stock=1;
    }while (bandera_stock==1);



    fwrite(&Tproducto, sizeof(Tproducto),1,archivo);//grabo al archivo

    printf("\n\nDesea seguir cargando? S/N ");
    fflush(stdin);
    scanf("%c", &sino);
    }while (sino == 's');
    fclose(archivo);
    return 0;
}
int cargarArchivo(tproducto tp[], int cant)
{
    FILE *archivoentrada;
    cant=0;
   tproducto  Tproducto;
    archivoentrada=fopen("Producto.bin","rb");
    if(archivoentrada == NULL)
        {printf("\n\nsale por error");
         getche();
         return -1;}
    fread(&Tproducto, sizeof(Tproducto),1,archivoentrada);
    while(!feof(archivoentrada)){
        tp[cant]=Tproducto;
        fread(&Tproducto, sizeof(tproducto),1,archivoentrada);
        cant++;
        }
    fclose(archivoentrada);
    return cant;
}
void modificar(tproducto tp[],int cant)
{
    int auxcodigo,pos=0;
    int bandera_precio=0, bandera_stock=0;
    system("cls");
    printf("Modificar producto");
    printf("\n\n\nIngrese el codigo del producto ");
    scanf("%d",&auxcodigo);
    pos=busquedabinario(tp,auxcodigo,cant);  //La variable pos recibe lo que devuelve la funcion
    if (pos >= 0)  //Recuerden que -1 no encuentran el producto
     {

        printf("\n\n La descripcion es %s", tp[pos].descripcion);
        getche();
        printf("\n\nIngrese la nueva descripcion   ");
        fflush(stdin);
        gets(tp[pos].descripcion);


        printf("\n\n\n El precios es %f\n",tp[pos].precio);
        getche();
        do{
        bandera_precio=0;
        printf("\n\nIngrese el nuevo precio   ");
        scanf("%f",&tp[pos].precio);
         if (tp[pos].precio<0)
            bandera_precio=1;
        }while (bandera_precio==1);//valido que el precio sea mayor a 0


        printf("\n\n\n La cantidad es %d n",tp[pos].cantidad);
        getche();
        do{
        bandera_stock=0;
        printf("\n\nIngrese la nueva cantidad   ");
        scanf("%d",&tp[pos].cantidad);
         if (tp[pos].cantidad<0)//valido que la cantidad sea mayor a 0
            bandera_stock=1;
        }while (bandera_stock==1);




    }
    else
    {
        printf("\n\nno encontro el producto\n");
        getche();
    }
}
void ordenarcodigo(tproducto tp[],int cant)
{
    int i,j,bandera=1;
   tproducto auxtp;
    for (i=0;i<cant && bandera==1;i++)
    {
    bandera=0;
        for(j=0;j<j-i-1;j++)
        {
            if(tp[j].codigo > tp[j+1].codigo)
            {
                auxtp=tp[j];
                tp[j]=tp[j+1];
                tp[j+1]=auxtp;
                bandera=1;
            }
        }

    }
}
//Aca busca por codigo - la busqueda es binaria
int busquedabinario(tproducto tp[],int auxcodigo,int cant)
{
    // busqueda binaria
    int minimo,maximo,medio;
    minimo=0;
    maximo=cant-1;
    if(tp[minimo].codigo == auxcodigo)
        return minimo;  //devuelve la posicion
    if (tp[maximo].codigo== auxcodigo)
     return maximo;  //devuelve la posicion

    while(maximo-minimo > 1){
        medio=(maximo+minimo)/2;
        if(tp[medio].codigo == auxcodigo)
               return medio;   //devuelve la posicion

        if (auxcodigo > tp[medio].codigo)
            minimo = medio;
        else maximo = medio;  }
    return -1;  //si no lo encuentra devuelve -1
}
void listar(tproducto tp[] , int cant)
{
    int i;
    system ("cls");
    printf("Listar Ordenado por codigo todos los productos ");
    printf("\n=========================");

    for(i=0; i<cant;i++)
        printf("\n\n\ncodigo: %d\ndescripcion : %s\nprecio %f \n cantidad : %d",tp[i].codigo,tp[i].descripcion,tp[i].precio ,tp[i].cantidad);
        getche();
}
int  ya_existe_Codigo(tproductotp[], int cant);// esta funcioon valida que el  mismo codigo no sea cargado 2 veces
{
    int bandera=0, j ;
    for( j=0;j<cant&&bandera==0;j++)
    { bandera=0;
        if(tproducto.codigo==tproducto.codigo){
        printf("\n\nEl codigo  ya esta cargado,  por favor ingrese otro numero . \n\n");
        bandera=1;

    }else if(bandera==0)
        printf ("PRODUCTOS CARGADOS CORRECTAMENTE");

    }

     return bandera ;
}



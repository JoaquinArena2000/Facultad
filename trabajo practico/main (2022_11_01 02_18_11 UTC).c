#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tam_articulo 5
int main()
{
char tipoarticulo[tam_articulo]  , articulos=0,Opciontransaccion=0,  menu1=0 ;

int stockarticulo[tam_articulo] ,constock=0 , consprecio=0, bandera=1 ,i  ,j , exit, menu2=0;
int CantidadAVender=0, Venta=0 ;


float precioarticulo[tam_articulo] ;
float PrecioPorcantidad=0;



   do
       {
             system("cls");
             printf  ("\nBIENVENIDO AL SISTEMA DE JOACOPROGRAMA\n");
             printf  ("\n\t |A-	    CARGAR DATOS\n : ") ;
             printf  ("\n\t |B-	    MOSTRAR PRECIO DE ARTICULOS\n :");
             printf  ("\n\t |C-      STOCK DE ARTICULOS\n :") ;
             printf  ("\n\t |D-	    VENTA\n : ") ;
             printf  ("\n\t |E-	    Salir del Sistema\n : ");

             printf  ("\n\n Tu opcion: ");
             fflush(stdin);
             scanf("%c", &menu1);
             menu1= toupper(menu1);


         if (menu1=='A' || menu1=='B' || menu1=='C'|| menu1=='D')//aqui se comprueba que la opcion de menu 1 sea correcta
         {
              if(menu1=='A') //cargar datos a los vectores
               {

                           system("cls");
                         printf  ("\n	Cargar datos\n") ;
                         printf  ("\n|1-	INGRESO DEL PRODUCTO(tipoArticulo)\n");
                         printf  ("\n|2-    INGRESO DEL STOCK(stockArticulo)\n");
                         printf  ("\n|3-	INGRESO DE PRECIO(precioArticulo)\n") ;
                         printf  ("\n|4-	VOLVER AL MENU ANTERIOR\n");
                            printf("\n\n Tu opcion ");
                            fflush(stdin);
                            scanf("%d" , &menu2);

                        if (menu2==1 || menu2==2 || menu2==3 )//aqui se comprueba si la opcion que ingreso es valida
                            {
                                switch (menu2)
                                {
                                    case 1 : //ingreso del producto (tipo articulo )

                                                  system("cls");
                                                  printf("ENTRASTE A LA OPCION DE CARGAR DATOS\n ");
                                         printf  ("\n	INGRESO DE PRODUCTOS \n") ;
                                         printf  ("\n|L-	LIMPIEZA \n");
                                         printf  ("\n|G-	GOLOSINAS \n");
                                         printf  ("\n|T-	LIBRERIA \n");
                                         printf  ("\n|E-	EMBUTIDOS \n");
                                         printf  ("\n|F-	FRESCO \n");
                                         printf ("\n\n ESPERANDO TU OPCION ");

                                          for (i=0;i<tam_articulo;i++)
                                          {
                                             do
                                             {
                                                 exit=0;
                                                 bandera=0;
                                                 printf("\n Ingrese el articulo numero %i  : "  ,i+1);
                                                 fflush(stdin);
                                                 scanf("%c" , &articulos);
                                                 articulos = toupper(articulos);
                                                  for(int j=0;j<tam_articulo&&bandera==0;j++)
                                                  {
                                                            if(articulos==tipoarticulo[j])
                                                                {
                                                                    printf("\n\nLa opcion %c ya esta cargada,  por favor ingrese letras validad [L,G,T,E,F]. \n\n",articulos);

                                                                    bandera=1;
                                                                 }
                                                   }
                                                if (bandera==0)
                                                {
                                                    if (articulos=='L'||articulos=='G'||articulos=='T'||articulos=='E'||articulos=='F')
                                                    {
                                                        tipoarticulo[i]=articulos;
                                                        printf("\nArticulo cargado con exito\n")  ;
                                                        exit=1;
                                                    }

                                                   else
                                                     printf("\nla letra ingresada es incorrecta , solo se admite [L,G,T,E,F]\n ");
                                                }


                                            }while(exit==0);

                                          }
                                                system("PAUSE");
                                                Sleep(1000);
                                             break;


                                    case 2 : //Aqui vamos a guardar el ingreso de stock de los articulos

                                       system("cls");
                                       printf("EL INGRESO DE STOCK DE ARTICULOS SOLO ADMITE NUMEROS MAYORES A 0  ");
                                         printf  ("\n|L-	LIMPIEZA\n ");
                                         printf  ("\n|G-	GOLOSINAS\n");
                                         printf  ("\n|T-	LIBRERIA\n");
                                         printf  ("\n|E-	EMBUTIDOS\n");
                                         printf  ("\n|F-	FRESCO\n");
                                        for (i=0;i<tam_articulo;i++)
                                        {
                                                do
                                               {
                                                    bandera=0;
                                                    printf("\nINGRESE EL STOCK DEL ARTICULO [%c] : ",tipoarticulo[i]  );
                                                    fflush(stdin);
                                                    scanf("%d",&stockarticulo[i]);
                                                    if (stockarticulo[i] > 0)
                                                    {
                                                     printf("\nSTOCK CARGADO CON EXITO \n");
                                                     bandera=1;
                                                    }
                                                    else
                                                   printf("\n DEBES INGRESAR CANTIDADES MAYORES A 0\n");

                                               } while (bandera==0 );
                                        }system("PAUSE");

                                       break;

                                    case 3 : //ingreso de precio (precio articulo)
                                        system("cls");
                                        printf("\nEL INGRESO DE PRECIOS DE ARTICULOS SOLO ADMITE NUMEROS MAYORES A 0 \n");
                                         printf  ("\n|L-	LIMPIEZA\n");
                                         printf  ("\n|G-	GOLOSINAS\n");
                                         printf  ("\n|T-	LIBRERIA\n");
                                         printf  ("\n|E-	EMBUTIDOS\n");
                                         printf  ("\n|F-	FRESCO\n");
                                        for(i=0;i<tam_articulo;i++)
                                        {
                                            do
                                            {
                                                 bandera=0;
                                                 printf("\nPORFAVOR INGRESE EL PRECIO DEL ARTICULO [%c] : ", tipoarticulo[i]);
                                                 scanf("%f", &precioarticulo[i]);
                                                   if (precioarticulo[i]> 0)
                                                   {
                                                     printf("\nPRECIO CARGADO CORRECTAMENTE\n ");
                                                     bandera=1;
                                                   }

                                                   else
                                                     printf("\n DEBES INGRESAR UN PRECIO MAYOR A 0\n ");
                                            }while (bandera==0);
                                        }
                                        system("PAUSE");
                                        Sleep(1000);

                                            break;

                                case 4:
                                    system ("cls");
                                    break;
                            }
                        }


                }


           if (menu1=='B')//mostrar precio de los articulos
           {   system("cls");

                do
                {
                    bandera=0;
                       printf("\tVENTANA PARA CONSULTAR PRECIO DE LOS ARTICULOS\n\n ");
                       printf  ("\n|0-	LIMPIEZA(L)\n");
                       printf  ("\n|1-	GOLOSINAS(G)\n");
                       printf  ("\n|2-	LIBRERIA(T)\n");
                       printf  ("\n|3-	EMBUTIDOS(E)\n");
                       printf  ("\n|4-	FRESCO(F)\n");
                       printf  ("\n|5-  salir del menu ");
                       printf("\n\n SOBRE CUAL ARTICULO DESEAS SABER EL PRECIO  ?" );
                       scanf("%d", &consprecio);
                       if (consprecio>=0 && consprecio<=5)
                             {
                              printf("\nEl ARTICULO [%c] SALE $ %2.f\n\n", tipoarticulo[consprecio], precioarticulo[consprecio] );
                              bandera=1;
                             }
                       else
                        {
                            printf("\nERROR SOLO SE ADMITE NUMEROS VUELVA A INGRESAR\n");
                            printf(" \nSELECCIONE UNICAMENTE NUMEROS ENTRE 1-5 INCLUSIVE\n ");
                            system("PAUSE");
                        }
                }while(bandera==0);
                system("PAUSE");
           }

           if (menu1=='C') //mostrar stock de los articulos
           {system("cls");

                  do
                  {
                      bandera=0;
                   printf("ESTA VENTANA MUESTRA EL STOCK DE ARTICULOS  SOLO SE ADMITEN NUMEROS DEL 1-6\n\n ");
                   printf  ("\n|0-	LIMPIEZA(L)\n ");
                   printf  ("\n|1-	GOLOSINAS(G)\n ");
                   printf  ("\n|2-	LIBRERIA(T)\n");
                   printf  ("\n|3-	EMBUTIDOS(E)\n");
                   printf  ("\n|4-	FRESCO(F)\n");
                   printf  ("\n|5-  salir del menu ");
                    printf("\nQue codigo de stock  deseas consultar?" );
                    scanf("%d", &constock);

                    if (constock>=0 && constock<=5)
                    {
                        printf("\nEl STOCK DEL ARTICULO DE %c  ES %d\n\n", tipoarticulo[constock], stockarticulo[consprecio] );
                        bandera=1;
                    }

                    else
                       {
                        printf("\nERROR SOLO SE ADMITE NUMEROS VUELVA A INGRESAR\n");
                        printf("\nSELECCIONE UNICAMENTE NUMEROS ENTRE 1-5 INCLUSIVE\n ");
                        system("PAUSE");
                       }
                  }while (bandera==0);

                    system("PAUSE");
           }
            if(menu1=='D') //aqui se venderan los articulos
            {
                system("cls");
                printf("\nSECCION DE COMPRAS BIENVENIDO\n");
                printf("\n TENEMOS ESTOS PRODUCTOS EN STOCK");
                printf  ("\n|	LIMPIEZA(L)\n");
                printf  ("\n|	GOLOSINAS(G)\n");
                printf  ("\n|	LIBRERIA (T)\n");
                printf  ("\n|   EMBUTIDOS (E)\n");
                printf  ("\n|	FRESCO (F)\n");
                printf("\nSELECCIONE EL NUMERO DEL ARTICULO QUE DESEAS COMPRAR \n");
                printf("\nCODIGO    | ARTICULO\n");
                for(i=0; i<tam_articulo; i++)
                {
                printf("\t%i - %c\n", i, tipoarticulo[i]);

                }
                printf("\nINGRESE EL NUMERO DE ARTICULO QUE DESEA COMPRAR : ");
                fflush(stdin);
                scanf("%d", &Venta);
               if (Venta==0 ||Venta==1 ||Venta==2 || Venta==3 || Venta==4)
               {
                       if(Venta<5)
                    {
                        printf("\nDATOS DE ARTICULO\n");
                        printf("\tARTICULO: %c\n", tipoarticulo[Venta]);

                        printf("\tPRECIO: $%.2f\n", precioarticulo[Venta]);
                        printf("\tSTOCK: %i\n", stockarticulo[Venta]);
                    }
                    else
                    {
                        printf("\nERROR INGRESE UN NUMERO ENTRE 0 Y 5 , SOLO DISPONEMOS DE ESA CANTIDAD DE PRODUCTOS \n" );
                        system("pause");

                    }

                    printf("\nINGRESE LA CANTIDAD QUE DESEA COMPRAR : ");
                    scanf("%d", &CantidadAVender);

                    if(CantidadAVender<=stockarticulo[Venta])
                    { system("cls");

                        PrecioPorcantidad = CantidadAVender*precioarticulo[Venta];

                        printf("\nUSTED VA A COMPRAR %i UNIDADES CON UN TOTAL DE $%.2f\n", CantidadAVender, PrecioPorcantidad);
                        printf("GENERANDO ENTORNO DE PAGO AGUARDE UN INSTANTE");
                        Sleep(3000);
                        printf("\nDESEA REALIZAR EL PAGO?\n");

                        printf("\nPRESIONE : [S] PARA CONTINUAR - [N] PARA CANCELAR: ");
                        fflush(stdin);
                        scanf("%c", &Opciontransaccion);
                        Opciontransaccion = toupper(Opciontransaccion);
                        if(Opciontransaccion == 'S')
                        {system("cls");
                            stockarticulo[Venta]=stockarticulo[Venta] - CantidadAVender;

                            printf("\nPAGO REALIZADO CON EXITO\n ");
                            printf("\nUSTED COMPRO %d UNIDADES\n" ,CantidadAVender );
                            printf("GRACIAS POR USAR JOACOPROGRAMA");
                            system("pause");
                        }
                        else
                        {
                            printf("\nCOMPRA CANCELADA \n");
                            system("pause");
                        }

                      }else
                      printf("\nLO SIENTO NO TENEMOS ESA CANTIDAD DE STOCK DISPONIBLE EN ESTE MOMENTO\n");
                      system("pause");
               }else
                printf("SOLO SE ADMITEN VALORES NUMERICOS ENTRE 0-5 , VUELVA A INGRESAR PORFAVOR");

           }


        }
         else
         {
           printf("\nSOLO SE ADMITEN LAS SIGIENTES LETRAS [A|B|C|D|E] Por favor vuelva a intentarlo\n'");
           system("PAUSE");
          }


   }while (menu1 != 'E');
   printf("\nGRACIAS POR USAR EL  SISTEMA JOACOPROGRAMA\n ");

    return 0;
}

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "temas.h"
#include "LinkedList.h"
#include "usuarios.h"
#include "string.h"
#include "utn.h"
#include "parser.h"



int main()
{
    LinkedList* listaUsuarios = ll_newLinkedList();
    LinkedList* listaTemas = ll_newLinkedList();

    int resp=1;

        if(parser_parseUsuarios("usuarios.dat",listaUsuarios)== 0)
        {
        printf("Datos Ingresados \n");
        }

        if(parser_parseTemas("temas.dat",listaTemas)== 0)

        {
        printf("Datos Ingresados \n");
        }
/*
    if(  ll_sort(listaUsuarios,usuarios_criterioSortNombre,1)==0)
     {

          usuarios_print(listaUsuarios);
      }

   /*   if (ll_sort(listaUsuarios,usuarios_criterioSortPaisYNombre,1)== 0)
      {
          usuarios_print(listaUsuarios);


      }*/


//
   if(   usuarios_verificarDatos(listaUsuarios)==0)
   {

    temas_print(listaTemas);

    }





           // res
                 //   break;
               // }
    //    }while (resp !=5);








    return 0;
}

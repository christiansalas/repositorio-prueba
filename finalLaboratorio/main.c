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


//do
   // {
       // scanf("%d",&resp);
               //printf("Ordenar por NOmbre \n");
               // switch(resp)
              //  {
               // case 1 :
                 if(   parser_parseUsuarios("usuarios.dat",listaUsuarios)== 0)
                    {
                     printf("Datos Ingresados \n");
                    }
           // resp= 5;
                 //   break;
               // }
    //    }while (resp !=5);








    return 0;
}

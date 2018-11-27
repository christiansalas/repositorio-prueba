#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Ventas.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"
#include "utn.h"



int main()
{
LinkedList* listaVentas = ll_newLinkedList();
//LinkedList* listaFiltrada = ll_newLinkedList();

if(parser_parseVentas("data.csv",listaVentas)==0)
{
    ventas_print(listaVentas);
    printf ("Archivo Creado con exito!!\n");
}




if( generarArchivoSueldos("informes.csv",listaVentas)==0)
{
    printf("creo el archivo\n");
}



    return 0;
}

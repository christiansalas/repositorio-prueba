#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();

    // Crear lista compras
    //...

    // Leer compras de archivo data.csv
    if(parser_parseCompras("data.csv",listaCompras)==1)
    {
        // Filtrar
        listaFiltrada = ll_filterConDosPrametro(listaCompras, Compra_PorId);

         emp_print(listaFiltrada);

        // Calcular montos
        printf("\nCalculando montos totales...\n");
        //TODO
        if(ll_map(listaFiltrada, Compra_CalcularMontoTotal)==0)
        {
            printf("ENTRO AL MAP \n");
        }
       // Compra_ImprimirEmpleado(listaFiltrada);


        // Generar archivo de salida
        if(generarArchivoInforme("informe.csv",listaFiltrada)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo compras\n");


    return 0;
}


int generarArchivoInforme(char* fileName,LinkedList* listaCompras)
{
    int retorno = -1;
    Compra * pCompras;
    int i;
    char bufferNombreCliente[128];
    float bufferPrecioUnitario;
    float bufferIva;
    float bufferMontoTotal;
    int bufferIdProducto;
    int bufferUnidades;
    FILE *pFile= fopen(fileName,"w");


    if(pFile!=NULL)
    {
        retorno = 0;
        fprintf(pFile,"bufferNombreCliente,bufferIdProducto,bufferPrecioUnitario,bufferUnidades,bufferIva,bufferMontoTotal\n");
        for(i=0;i<ll_len(listaCompras);i++)
        {
            pCompras=ll_get(listaCompras,i);
            Compra_getIdProducto(pCompras,&bufferIdProducto);
            Compra_getNombreCliente(pCompras,bufferNombreCliente);
            Compra_getIva(pCompras,&bufferIva);
            Compra_getUnidades(pCompras,&bufferUnidades);
            Compra_getPrecioUnitario(pCompras,&bufferPrecioUnitario);
            Compra_getMontoTotal(pCompras,&bufferMontoTotal);
                if (bufferIdProducto>= 0 && bufferNombreCliente != NULL && bufferIva >= 0 && bufferPrecioUnitario >= 0 && bufferUnidades >= 0 && bufferMontoTotal >= 0)
             {
                fprintf(pFile,"\%s,%d,%f,%d,%f,%f\n", bufferNombreCliente, bufferIdProducto, bufferPrecioUnitario, bufferUnidades, bufferIva, bufferMontoTotal);
                retorno = 1;
             }
        }

    }


    return 1;
}


/*
#include "Compra.h"

void com_calcularMonto(void* p)
{

}




#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED

struct S_Compra
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
};
typedef struct S_Compra Compra;

void com_calcularMonto(void* p);

#endif // COMPRA_H_INCLUDED*/

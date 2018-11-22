#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Ventas.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"
#include "utn.h"




int parser_parseVentas(char* fileName, LinkedList* lista)
{
    int retorno = -1;
    char* delimitador = ",";
    char * bufferLine[1024];
    char* token;
    FILE* pFile;
    pFile = fopen(fileName, "r");
    int flagonce = 1;
    char bufferIdVenta [1024];
    char bufferFechaVenta[1024];
    char bufferCodigoProducto[1024];
    char bufferCantidad[1024];
    char BufferPrecioUnitario[1024];
    char bufferCuitCliente[1024];


    Venta * pVenta = NULL;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(!flagonce)
            {
               fscanf(pFile,"%[^\n]\n",bufferLine);
               flagonce = 0;
            }
             fscanf(pFile,"%[^\n]\n",bufferLine);
             token = strtok(bufferLine, delimitador);
             strncpy(bufferIdVenta, token, 1024);

             token = strtok(NULL,delimitador);
             strncpy(bufferFechaVenta,token,1024);

             token = strtok(NULL,delimitador);
             strncpy(bufferCodigoProducto,token,1024);

             token = strtok(NULL,delimitador);
             strncpy(bufferCantidad,token,1024);

             token = strtok(NULL,delimitador);
             strncpy(BufferPrecioUnitario,token,1024);

             token = strtok(NULL,delimitador);
             strncpy(bufferCuitCliente,token,1024);

             pVenta =Ventas_newConParametros(bufferIdVenta,bufferFechaVenta,bufferCodigoProducto,BufferPrecioUnitario,bufferCuitCliente,bufferCantidad);
             //Ventas_newConParametros(bufferIdVenta,bufferFechaVenta,bufferCodigoProducto,BufferPrecioUnitario,bufferCuitCliente);
             if(pVenta != NULL)
             {
                 ll_add(lista,pVenta);
                 retorno = 1;
                 printf("%s - %s - %s - %s - %s - %s \n", bufferIdVenta, bufferFechaVenta, bufferCodigoProducto,BufferPrecioUnitario, bufferCuitCliente, bufferCantidad);
             }
        }
    }

    return retorno;
}



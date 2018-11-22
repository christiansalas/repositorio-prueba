#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"


/*int parser_parseCompras(char* fileName, LinkedList* lista)
{
    printf("enTRO");

char bufferLine[1024];
char* delimitador = ",";
char* token;
int idProducto;
float precioUnitario;
int unidades ;
float iva;
Compra * pCompra;
char bufferNombre[1024];
int retorno = -1;
int flagOnce = 1;
FILE* pFile;
pFile=fopen(fileName,"r");
float  montoTotal;


            if(pFile!=NULL)
            {
                while(!feof(pFile))
                    {

                        if(flagOnce==1)
                            {
                                fscanf(pFile,"%[^\n]\n",bufferLine);
                                flagOnce = 0;
                            }
                             fscanf(pFile,"%[^\n]\n",bufferLine);

                                token = strtok(bufferLine, delimitador);

                                    strncpy(bufferNombre, token, 1024);
                                    token = strtok(NULL, delimitador);
                                    idProducto=atoi(token);
                                    token = strtok(NULL, delimitador);
                                    precioUnitario= atof(token);
                                    token = strtok(NULL, delimitador);
                                    unidades=atoi(token);
                                    token = strtok(NULL, delimitador);
                                    iva=atof(token);
                                    token = strtok(NULL, "\n");
                                    montoTotal=unidades*precioUnitario*(1+iva/100);

                                    pCompra= Compra_newConParametros(bufferNombre,precioUnitario,iva,montoTotal,idProducto,unidades);
                                   // printf("%s,%.2f,%.2f,%.2f,%d,%d\n",bufferNombre,precioUnitario,iva,montoTotal,idProducto,unidades);

                                if(pCompra=!NULL)
                                {
                                    retorno = 0;
                                    ll_add(lista,pCompra);

                                }
                    }
                }

    return 1; // OK
}*/
int parser_parseCompras(char* fileName, LinkedList* lista)
{
    int retorno = -1;
    char* delimitador = ",";
    char * bufferLine[1024];
    char* token;
    FILE* pFile;
    pFile = fopen(fileName, "r");
    int flagonce = 1;
    char bufferNombre[1024];
    char bufferIdProducto[1024];
    char bufferPrecio[1024];
    char bufferUnidades[1024];
    char BufferIva[1024];
    char bufferMonto[1024];
    strncpy(bufferMonto, "0", 1024);
    Compra * pCompra = NULL;
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
             strncpy(bufferNombre, token, 1024);
             token = strtok(NULL,delimitador);
             strncpy(bufferIdProducto,token,1024);
             token = strtok(NULL,delimitador);
             strncpy(bufferPrecio,token,1024);
             token = strtok(NULL,delimitador);
             strncpy(bufferUnidades,token,1024);
             token = strtok(NULL,delimitador);
             strncpy(BufferIva,token,1024);
             pCompra = Compra_newConParametros(bufferNombre, bufferPrecio, BufferIva, bufferMonto, bufferIdProducto, bufferUnidades);
             if(pCompra != NULL)
             {
                 ll_add(lista, pCompra);
                 retorno = 1;
                 //printf("%s - %s - %s - %d - %s - %s \n", bufferNombre, bufferPrecio, BufferIva,bufferMonto, bufferIdProducto, bufferUnidades);
             }
        }
    }

    return retorno;
}



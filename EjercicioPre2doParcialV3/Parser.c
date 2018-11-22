#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"


int parser_parseCompras(char* fileName, LinkedList* lista)
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
                                    ll_add(lista,pFile);

                                }
                    }
                }

    return 1; // OK
}


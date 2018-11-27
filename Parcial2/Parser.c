#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Ventas.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param fileName char* Es el nombre del archivo donde se encuentran las ventas
 * \param lista LinkedList* Es la LinkedList donde se guardan las ventas cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y 1 si no se pudo cargar.
 *
 */
int parser_parseVentas(char* fileName, LinkedList* listaVentas)
{
    int retorno = -1;
    char bufferId[1024];
    char bufferFecha[1024];
    char bufferCodigo[1024];
    char buferCantidad[1024];
    char BufferPrecio[1024];
    char bufferCuit[1024];
    int flagOnce = 1;
    Venta* pVentas;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                        bufferId,
                        bufferFecha,
                        bufferCodigo,
                        buferCantidad,
                        BufferPrecio,
                        bufferCuit);
                flagOnce = 0;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                        bufferId,
                        bufferFecha,
                        bufferCodigo,
                        buferCantidad,
                        BufferPrecio,
                        bufferCuit);

            pVentas = ventas_newConParametros( bufferId, bufferFecha, bufferCodigo, buferCantidad, BufferPrecio, bufferCuit);
            if(pVentas != NULL)
            {
                retorno = 0;
                ll_add(listaVentas, pVentas);

            }
        }
    }
    return retorno;
}

/** \brief Guarda el informe de las ventas
 *
 * \param fileName char* Es el nombre del archivo donde se guardan los informes
 * \param listaVentas LinkedList* Es la LinkedList donde se guardan las ventas
 * \return int retorna 0 si el archivo se guardo correctamente, y 1 si no se pudo cargar.
 *
 */

int generarArchivoSueldos(char* fileName,LinkedList* unidadesVendidas)
{
int retorno = 1;
int i;
int cantidadVentas;
int Mayor10000;
int Mayor20000;
int cantTVs;
FILE* pFile = fopen(fileName,"w");

    if(pFile != NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(unidadesVendidas);i++)
        {
            cantidadVentas = ll_count(unidadesVendidas, Venta_VentasTotales);
            Mayor10000 = ll_count(unidadesVendidas, Ventas_calcularVentasMayor10000);
            Mayor20000 = ll_count(unidadesVendidas, Ventas_calcularVentasMayor20000);
            cantTVs = ll_count(unidadesVendidas, Ventas_calcularVentasLCD);
        }
         fprintf(pFile,"\nCantidad de ventas :%d\nVentas Superan los 10000 :%d\nVentas superan los 20000: %d\nTVs vendidas :%d\n",  cantidadVentas,
                                            Mayor10000,
                                            Mayor20000,
                                            cantTVs);
    }
    return retorno;
}



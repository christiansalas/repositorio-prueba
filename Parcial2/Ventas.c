#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Ventas.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"
#include "utn.h"

/**
 * \brief Asigna el espacio de memoria para la creacion de una venta
 * \return Venta* En caso de exito retorna el puntero a la venta, si no NULL
 *
 */
Venta* Ventas_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}
/**
 * \brief Libera el espacio de memoria donde se encontraba la venta utilizando free()
 *
 * \param this Employee* Es el empleado que se desea eliminar
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
void Ventas_delete(Venta* this)
{
    free(this);
}

/**
 * \brief Asigna el espacio de memoria para la creacion de un venta con todos sus atributos cargados
 * \return Employee* En caso de exito retorna el puntero al empleado, si no NULL
 *
 */
Venta* ventas_newConParametros(char* idVentas,char* fecha_venta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuit)
{
    Venta* this;
    this=Ventas_new();

    if(
    !Ventas_setIdVenta(this,atoi(idVentas))&&
    !Ventas_setFechaVenta(this,fecha_venta)&&
    !Ventas_setCodigoProducto(this,codigoProducto)&&
    !Ventas_setCantidadVentas(this,atoi(cantidad))&&
    !ventas_setPrecioUnitario(this, atof(precioUnitario))&&
    !Ventas_setCuitCliente(this,cuit))
        return this;

    Ventas_delete(this);
    return NULL;
}
/**
 * \brief Setter del id
 *
 * \param this Venta* Es la venta donde se guarda el id
 * \param int id Es el id que se guarda en la venta
 * \return En caso de exito retorna 1, si no 0
 *
 */
int Ventas_setIdVenta(Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int Ventas_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Ventas_setFechaVenta(Venta* this,char* FechaVenta)
{
    int retorno=-1;
    if(this!=NULL && FechaVenta!=NULL)
    {
        strcpy(this->FechaVenta,FechaVenta);
        retorno=0;
    }
    return retorno;
}

int Ventas_getFechaVenta(Venta* this,char* FechaVenta)
{
    int retorno=-1;
    if(this!=NULL && FechaVenta!=NULL)
    {
        strcpy(FechaVenta,this->FechaVenta);
        retorno=0;
    }
    return retorno;
}

int Ventas_setCodigoProducto(Venta* this,char *codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}
int ventas_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

int ventas_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}


int ventas_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int ventas_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_setCuitCliente(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(this->cuitCliente,cuit);
        retorno=0;
    }
    return retorno;
}

int Ventas_getCuitCliente(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}
int Ventas_setCantidadVentas(Venta* this,int cantidadVentas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadVentas=cantidadVentas;
        retorno=0;
    }
    return retorno;
}

int Ventas_getCantidadVentas(Venta* this,int* cantidadVentas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadVentas=this->cantidadVentas;
        retorno=0;
    }
    return retorno;
}

/**
 * \brief filtra ventas por monto.
 *
 * \param pElement Venta* Es la venta que se calcula el monto
 * \param m
 * \return retorna 1 si la venta supera los 20.000 y 0 si no.
 *
 */
int Ventas_calcularVentasMayor10000(void* pElement)
{
    int returnAux = 0;
    int cantidad;
    float precio;
    int auxTotal;
    Venta * pVenta= pElement;


    if(pElement!= NULL )
        {
            ventas_getPrecioUnitario(pVenta,&precio);
            Ventas_getCantidadVentas(pVenta,&cantidad);
            auxTotal= precio*cantidad;
        if(auxTotal>10000)
            {
             returnAux=1;
            }
        }

    return returnAux;
}

/**
 * \brief Filtra las ventas por el monto total
 *
 * \param pElement void* Es la venta donde se evalua la cantidad
 * \return retorna 1 si la venta es mayor al monto
 *
 */

int Ventas_calcularVentasMayor20000(void* pElement)
{
    int returnAux = 0;
    int cantidad;
    float precio;
    int auxTotal;
    Venta * pVenta= pElement;


    if(pElement!= NULL )
        {
            ventas_getPrecioUnitario(pVenta,&precio);
            Ventas_getCantidadVentas(pVenta,&cantidad);
            auxTotal= precio*cantidad;
        if(auxTotal>20000)
            {
             returnAux=1;
            }
        }

    return returnAux;
}

/**
 * \brief Filtra las ventas Por codigo de Producto.
 *
 * \param pElement void* Es la venta donde se evalua la cantidad
 * \return retorna 1 si El codigo es el comparado y 0 si no lo es.
 *
 */
int Ventas_calcularVentasLCD(void* pElement)
{
int retorno = 0;
Venta* pVenta = pElement;
char auxProducto[1024];


         if(pVenta !=NULL )
            {
            ventas_getCodigoProducto(pVenta,auxProducto);
            if(strncmp(auxProducto,"LCD_TV",1024)==0)
              retorno = 1;

            }
    return retorno;
}

/**
 * \brief Filtra las ventas por el monto total
 *
 * \param thisVoid void* Es la venta donde se evalua la cantidad
 * \return Int Retorna la cantidad de unidades
 *
 */

int Venta_VentasTotales(void*pElement)
{
Venta*pVenta=pElement;
int retorno = 0;

    if(pElement !=NULL)

    {
        retorno=pVenta->cantidadVentas;
    }
    return retorno;

}


/**
 * \brief Imprime las ventas de los clientes
 *
 * \param this es el puntero a la linkendlist
 * \return Int Retorna 0 si puede imprimir.
 *
 */

int ventas_print(LinkedList* this)
 {
   int retorno = -1;
   Venta * pVentas = NULL;
   int bufferId;
   char bufferFecha[1024];
   int bufferCodigo[1024];
   int buferCantidad;
   float BufferPrecio;
   char bufferCuit[1024];
   int i;
    if(this != NULL)
    {
        for (i = 0; i< ll_len(this); i++)
        {
             pVentas = ll_get(this,i);
             Ventas_getIdVenta(pVentas, &bufferId);
             Ventas_getFechaVenta(pVentas, bufferFecha);
            ventas_getCodigoProducto(pVentas,bufferCodigo);
             Ventas_getCantidadVentas(pVentas, &buferCantidad);

             ventas_getPrecioUnitario(pVentas,&BufferPrecio);
             Ventas_getCuitCliente(pVentas, bufferCuit);
             printf("\nId %d - Fecha: %s -Codigo: %s - Cantidad: %d - Precio: %.2f - Cuit: %s \n"
             ,bufferId, bufferFecha, bufferCodigo, buferCantidad, BufferPrecio, bufferCuit );
             retorno = 0;
        }
    }

    return retorno;
 }




#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Ventas.h"
#include "LinkedList.h"
#include "Parser.h"
#include "string.h"
#include "utn.h"


Venta* Ventas_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Ventas_delete(Venta* this)
{
    free(this);
}

Venta* Ventas_newConParametros(int idVenta,char* FechaVenta,int codigoProducto,int precioUnitario,char cuitCliente,int cantidadVentas)
{
    Venta* this;
    this=Ventas_new();
    /*
       int idVenta;
    char FechaVenta[1024];
    int codigoProducto;
    int precioUnitario;
    char cuitCliente;
    int cantidadVentas;*/

    if(
    !Ventas_setIdVenta(this,atoi(idVenta))&&
    !Ventas_setFechaVenta(this,FechaVenta)&&
    !Ventas_setCodigoProducto(this,atoi(codigoProducto))&&
    !Ventas_setPrecioUnitario(this,atof(precioUnitario))&&
    !Ventas_setCuitCliente(this,cuitCliente)&&
    !Ventas_setCantidadVentas(this,atoi(cantidadVentas)))
        return this;

    Ventas_delete(this);
    return NULL;
}

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

int Ventas_setCodigoProducto(Venta* this,int codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->codigoProducto=codigoProducto;
        retorno=0;
    }
    return retorno;
}

int Ventas_getCodigoProducto(Venta* this,int* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *codigoProducto=this->codigoProducto;
        retorno=0;
    }
    return retorno;
}

int Ventas_setPrecioUnitario(Venta* this,int precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_getPrecioUnitario(Venta* this,int* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_setCuitCliente(Venta* this,char cuitCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cuitCliente=cuitCliente;
        retorno=0;
    }
    return retorno;
}

int Ventas_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cuitCliente=this->cuitCliente;
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
/*
int Compra_CalcularVentasTotales(void* pElement)
{
int retorno = -1;
Venta* pVenta = pElement;
float bufferUnidadesVendidas;

    if(pElement!= NULL)
    {
        bufferPrecioUnitario=(pCompra->unidades*pCompra->precioUnitario);
        pCompra->montoTotal=bufferPrecioUnitario*(1+pCompra->iva/100);
        retorno = 1;

    }
    return retorno;

}*/

int em_calcularVentas(void* pElement)
{
    int returnAux = -1;
    Venta* pVenta = pElement;
    float PrecioUnitario = pVenta->precioUnitario;
    int  Cantidad= pVenta->cantidadVentas;
    int acumulador1=0;
    int acumulador2=0;
    float auxTotal;



    auxTotal=PrecioUnitario*Cantidad;

    if(pElement != NULL)
    {
        returnAux = 1;

        if(auxTotal>= 10000)
        {
            acumulador1=acumulador1+1;
        }
        if(auxTotal> 20000)
                    {
                        acumulador2=acumulador2+1;
                    }

            printf("Cantidad de ventas que superan los $10.000 son : %d\n",acumulador1);
            printf("Cantidad de ventas que superan los $20.000 son : %d",acumulador2);


    }
    return returnAux;
}







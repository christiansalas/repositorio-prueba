#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "temas.h"
#include "LinkedList.h"
#include "usuarios.h"
#include "string.h"
#include "utn.h"
#include "parser.h"



Usuarios* usuarios_new()
{
    Usuarios* this;
    this=malloc(sizeof(Usuarios));
    return this;
}

void usuarios_delete(Usuarios* this)
{
    free(this);
}

Usuarios* usuarios_newConParametros(char* id,char* nombre,char* email,char* sexo,char* pais,char* passdword,char* ipAdress)
{
    Usuarios* this;
    this=usuarios_new();

    if(
    !usuarios_setId(this,atoi(id))&&
    !usuarios_setNombre(this,nombre)&&
    !usuarios_setEmail(this,email)&&
    !usuarios_setSexo(this,sexo)&&
    !usuarios_setPais(this,pais)&&
    !usuarios_setPassdword(this,passdword)&&
    !usuarios_setIpAdress(this,ipAdress))
        return this;

    usuarios_delete(this);
    return NULL;
}

int usuarios_setId(Usuarios* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int usuarios_getId(Usuarios* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int usuarios_setNombre(Usuarios* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int usuarios_getNombre(Usuarios* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int usuarios_setEmail(Usuarios* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int usuarios_getEmail(Usuarios* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}

int usuarios_setSexo(Usuarios* this,char* sexo)
{
    int retorno=-1;
    if(this!=NULL && sexo!=NULL)
    {
        strcpy(this->sexo,sexo);
        retorno=0;
    }
    return retorno;
}

int usuarios_getSexo(Usuarios* this,char* sexo)
{
    int retorno=-1;
    if(this!=NULL && sexo!=NULL)
    {
        strcpy(sexo,this->sexo);
        retorno=0;
    }
    return retorno;
}

int usuarios_setPais(Usuarios* this,char* pais)
{
    int retorno=-1;
    if(this!=NULL && pais!=NULL)
    {
        strcpy(this->pais,pais);
        retorno=0;
    }
    return retorno;
}

int usuarios_getPais(Usuarios* this,char* pais)
{
    int retorno=-1;
    if(this!=NULL && pais!=NULL)
    {
        strcpy(pais,this->pais);
        retorno=0;
    }
    return retorno;
}

int usuarios_setPassdword(Usuarios* this,char* passdword)
{
    int retorno=-1;
    if(this!=NULL && passdword!=NULL)
    {
        strcpy(this->passdword,passdword);
        retorno=0;
    }
    return retorno;
}

int usuarios_getPassdword(Usuarios* this,char* passdword)
{
    int retorno=-1;
    if(this!=NULL && passdword!=NULL)
    {
        strcpy(passdword,this->passdword);
        retorno=0;
    }
    return retorno;
}

int usuarios_setIpAdress(Usuarios* this,char* ipAdress)
{
    int retorno=-1;
    if(this!=NULL && ipAdress!=NULL)
    {
        strcpy(this->ipAdress,ipAdress);
        retorno=0;
    }
    return retorno;
}

int usuarios_getIpAdress(Usuarios* this,char* ipAdress)
{
    int retorno=-1;
    if(this!=NULL && ipAdress!=NULL)
    {
        strcpy(ipAdress,this->ipAdress);
        retorno=0;
    }
    return retorno;
}


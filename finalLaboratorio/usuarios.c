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

/*
int usuarios_sort(void* pElement, void* pElement2)
{

int  retorno = -1;
    Usuarios *pUsuario=pElement;
    Usuarios *pUsuario2= pElement2;
    char pBufferNombre[1024];
    char pbufferNombre2[1024];

    if(pElement!=NULL &&  pElement2 !=NULL)
    {

      if(strncmp(pUsuario->nombre,pUsuario2->nombre,1024)<0)
      {
         retorno = -1;

      }
      else if(strncmp(pUsuario->nombre,pUsuario2->nombre,1024)>0)
       {
           retorno = 1;
       }
       return retorno;

    }

  return retorno;
}*/


int usuarios_print(LinkedList* this)
 {



   int retorno = -1;
   Usuarios * pUsuarios = NULL;
   int bufferId;
   char bufferNombre[1024];
   char bufferEmail[1024];
   char bufferSexo[1024];
   char bufferPais[1024];
   char bufferPassword[1024];
    char bufferIpAdress[1024];

   int i;
    if(this != NULL)
    {
        for (i = 0; i< ll_len(this); i++)
        {
                pUsuarios= ll_get(this,i);
                usuarios_getId(pUsuarios, &bufferId);
                usuarios_getNombre(pUsuarios,bufferNombre);
                usuarios_getEmail(pUsuarios,bufferEmail);
                usuarios_getSexo(pUsuarios,bufferSexo);
                usuarios_getPais(pUsuarios,bufferPais);
                usuarios_getPassdword(pUsuarios,bufferPassword);
                usuarios_getIpAdress(pUsuarios,bufferIpAdress);

             printf("\nId %d - Nombre: %s -Email: %s - Sexo: %s - Pais: %s - Passwd: %s- Ip : %s \n"
             ,bufferId,bufferNombre, bufferEmail, bufferSexo, bufferPais, bufferPassword, bufferIpAdress );
             retorno = 0;
        }
    }

    return retorno;
 }

 int usuarios_criterioSortNombre(void* thisA,void* thisB)
{
    char nombreA[100];
    char nombreB[100];
    int retorno = 0;

    if(thisA != NULL && thisB != NULL)
    {
        usuarios_getNombre(thisA,nombreA);
        usuarios_getNombre(thisB,nombreB);
        if(strcmp(nombreA,nombreB) > 0)
        {
            retorno = 1;
        }
        else if(strcmp(nombreA,nombreB) < 0)
        {
           // printf("\nMENOR");
            retorno = -1;
        }
    }
    return retorno;
}
int usuarios_criterioSortPaisYNombre(void* thisA,void* thisB)
{
    char nombreA[100];
    char nombreB[100];
    char paisA[100];
    char paisB[100];
    int retorno = 0;

    if(thisA != NULL && thisB != NULL  )
    {
        usuarios_getNombre(thisA,nombreA);
        usuarios_getNombre(thisB,nombreB);
        usuarios_getPais(thisA,paisA);
        usuarios_getPais(thisB,paisB);
        if(strcmp(paisA,paisB) > 0 && strcmp(nombreA,nombreB)> 0)
        {
            retorno = 1;
        }
        else if(strcmp (paisA,paisB)< 0 && strcmp(nombreA,nombreB) < 0)
        {
           // printf("\nMENOR");
            retorno = -1;
        }
    }
    return retorno;
}


int usuarios_verificarDatos(LinkedList * this)
{
int retorno = -1;

    Usuarios*pUsuarios;
    char bufferNick[1024];
    char bufferClave[1024];
    char BufferTema[1024];
    int i;
    char bufferNombreAux[1024];
        char bufferPasswdAux[1024];


    if(this!= NULL)
    {

      if( utn_getNombre(bufferNick,1024,"Ingrese NIck \n","Ingrese un Nick Correcto \n",2)== 0&&
         utn_getTexto(bufferClave,1024,"Ingrese Clave de Letras\n","Error, clave incorrecta \n",2)==0
         )
      {
        for(i=0;i<ll_len(this);i++)
            {
                pUsuarios=ll_get(this,i);
                usuarios_getNombre(pUsuarios,bufferNombreAux);
                usuarios_getPassdword(pUsuarios,bufferPasswdAux);

               if(strncmp(bufferNick,bufferNombreAux,1024)== 0 && strncmp(bufferClave,bufferPasswdAux,1024)== 0)
                   {
                       retorno = 0;
                       break;
                   }

            }

      }


    }




    return retorno;
}




#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "temas.h"
#include "LinkedList.h"
#include "usuarios.h"
#include "string.h"
#include "utn.h"
#include "parser.h"



Temas* temas_new()
{
    Temas* this;
    this=malloc(sizeof(Temas));
    return this;
}

void temas_delete(Temas* this)
{
    free(this);
}

Temas* temas_newConParametros(int id,char* nombre_Tema,char* artista,int idUsuario)
{
    Temas* this;
    this=temas_new();

    if(
    !temas_setId(this,atoi(id))&&
    !temas_setNombre_Tema(this,nombre_Tema)&&
    !temas_setArtista(this,artista)&&
    !temas_setIdUsuario(this,idUsuario))
        return this;

    temas_delete(this);
    return NULL;
}

int temas_setId(Temas* this,int id)
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

int temas_getId(Temas* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int temas_setNombre_Tema(Temas* this,char* nombre_Tema)
{
    int retorno=-1;
    if(this!=NULL && nombre_Tema!=NULL)
    {
        strcpy(this->nombre_Tema,nombre_Tema);
        retorno=0;
    }
    return retorno;
}

int temas_getNombre_Tema(Temas* this,char* nombre_Tema)
{
    int retorno=-1;
    if(this!=NULL && nombre_Tema!=NULL)
    {
        strcpy(nombre_Tema,this->nombre_Tema);
        retorno=0;
    }
    return retorno;
}

int temas_setArtista(Temas* this,char* artista)
{
    int retorno=-1;
    if(this!=NULL && artista!=NULL)
    {
        strcpy(this->artista,artista);
        retorno=0;
    }
    return retorno;
}

int temas_getArtista(Temas* this,char* artista)
{
    int retorno=-1;
    if(this!=NULL && artista!=NULL)
    {
        strcpy(artista,this->artista);
        retorno=0;
    }
    return retorno;
}

int temas_setIdUsuario(Temas* this,int idUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idUsuario=idUsuario;
        retorno=0;
    }
    return retorno;
}

int temas_getIdUsuario(Temas* this,int* idUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idUsuario=this->idUsuario;
        retorno=0;
    }
    return retorno;
}

int temas_print(LinkedList* this)
 {

   int retorno = -1;
   Temas * ptemas = NULL;
   int bufferId;
   char bufferNombreTema[1024];
   char bufferArtista[1024];
   int i;
    if(this != NULL)
    {
        for (i = 0; i< ll_len(this); i++)
        {
                ptemas= ll_get(this,i);
                temas_getId(ptemas, &bufferId);
                temas_getNombre_Tema(ptemas,bufferNombreTema);
                temas_getArtista(ptemas,bufferArtista);

             printf("\nId %d - NombreTema: %s -Artista: %s \n"
             ,bufferId,bufferNombreTema, bufferArtista);
             retorno = 0;
        }
    }

    return retorno;
 }


 int temas_verificarTemas(LinkedList* this)
 {
     int retorno =-1;
     int i;
     Temas *pTemas;

    int bufferIdTema;
    int bufferiDAuxiliar;


     if(this != NULL)
     {
       if( utn_getEntero(&bufferIdTema,1024,"Ingrese Id del Tema \n","Error",2)==0)
       {

           for (i=0;i<ll_len(this);i++)
           {
            pTemas=ll_get(this,i);
            temas_getId(pTemas,bufferiDAuxiliar);
            if(bufferiDAuxiliar==bufferIdTema)
            {
                retorno = 0;
            }

           }
       }



     }





 }


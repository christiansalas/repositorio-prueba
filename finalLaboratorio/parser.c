#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "temas.h"
#include "LinkedList.h"
#include "usuarios.h"
#include "string.h"
#include "utn.h"
#include "parser.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param fileName char* Es el nombre del archivo donde se encuentran las ventas
 * \param lista LinkedList* Es la LinkedList donde se guardan las ventas cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y 1 si no se pudo cargar.
 *
 */
int parser_parseUsuarios(char* fileName, LinkedList* listaUsuarios)
{

    char bufferLine[1024];
    char* delimitador = ",";
    char* token;
    int retorno = -1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferEmail[1024];
    char bufferSexo[1024];
    char bufferPais[1024];
    char BufferPassword[1024];
    char bufferIpAdress[1024];
    int flagOnce = 1;
    Usuarios* pUsuario;
    FILE* pFile;
    pFile = fopen(fileName,"r");

     if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce && fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                flagOnce = 0;
            }
            if(fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                token = strtok(bufferLine, delimitador);

                strncpy(bufferId, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferNombre, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferEmail, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferSexo, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferPais, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(BufferPassword, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferIpAdress, token, 1024);

// printf("\nId %s - nombre: %s -email: %s - sexo: %s - pais: %s - passwd: %s- ip : %s  \n"
//             ,bufferId, bufferNombre, bufferEmail, bufferSexo, bufferPais, BufferPassword,bufferIpAdress );

                pUsuario = usuarios_newConParametros(bufferId,bufferNombre,bufferEmail,bufferSexo,bufferPais,BufferPassword,bufferIpAdress);
            }
            if(pUsuario != NULL)
            {
                retorno = 0;
                ll_add(listaUsuarios, pUsuario);
            }
        }
    }
    return retorno;
}




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param fileName char* Es el nombre del archivo donde se encuentran las ventas
 * \param lista LinkedList* Es la LinkedList donde se guardan las ventas cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y 1 si no se pudo cargar.
 *
 */

int parser_parseTemas(char* fileName, LinkedList* listaTemas)
{


char bufferLine[1024];
char* delimitador = ",";
char* token;

int retorno = -1;
char bufferId[1024];
char bufferNombre_Tema[1024];
char bufferArtista[1024];

    int flagOnce = 1;
    Temas* pTemas;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce && fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                flagOnce = 0;
            }
            if(fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                token = strtok(bufferLine, delimitador);

                strncpy(bufferId, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferNombre_Tema, token, 1024);
                token = strtok(NULL, delimitador);

                strncpy(bufferArtista, token, 1024);

// printf("\nId %s - nombre del tema: %s -Artista: %s \n"
            // ,bufferId, bufferNombre_Tema, bufferArtista );

                pTemas = temas_newConParametros(bufferId,bufferNombre_Tema,bufferArtista,NULL);
            }
            if(pTemas != NULL)
            {
                retorno = 0;
                ll_add(listaTemas, pTemas);
            }
        }
    }
    return retorno;
    }



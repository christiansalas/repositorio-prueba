#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

//int parser_parseCompras(char* fileName, LinkedList* lista);

int generarArchivoSueldos(char* fileName,LinkedList* unidadesVendidas);

int parser_parseVentas(char* fileName, LinkedList* listaVentas);



#endif // PARSER_H_INCLUDED



typedef struct
{
    int id;
    char nombre[1024];
    char email[1024];
    char sexo[1024];
    char pais[1024];
    char passdword[1024];
    char ipAdress[1024];
}Usuarios;




Usuarios* usuarios_new();
void usuarios_delete();
Usuarios* usuarios_newConParametros(char* id,char* nombre,char* email,char* sexo,char* pais,char* passdword,char* ipAdress);

int usuarios_setId(Usuarios* this,int id);
int usuarios_getId(Usuarios* this,int* id);

int usuarios_setNombre(Usuarios* this,char* nombre);
int usuarios_getNombre(Usuarios* this,char* nombre);

int usuarios_setEmail(Usuarios* this,char* email);
int usuarios_getEmail(Usuarios* this,char* email);

int usuarios_setSexo(Usuarios* this,char* sexo);
int usuarios_getSexo(Usuarios* this,char* sexo);

int usuarios_setPais(Usuarios* this,char* pais);
int usuarios_getPais(Usuarios* this,char* pais);

int usuarios_setPassdword(Usuarios* this,char* passdword);
int usuarios_getPassdword(Usuarios* this,char* passdword);

int usuarios_setIpAdress(Usuarios* this,char* ipAdress);
int usuarios_getIpAdress(Usuarios* this,char* ipAdress);
//int usuarios_sort(void* pElement, void* pElement2);
int usuarios_print(LinkedList* this);
 int usuarios_criterioSortNombre(void* thisA,void* thisB);
 int usuarios_criterioSortPaisYNombre(void* thisA,void* thisB);
 int usuarios_verificarDatos(LinkedList * this);






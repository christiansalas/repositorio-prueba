
typedef struct
{
    int id;
    char nombre_Tema[1024];
    char artista[1024];
    int idUsuario;
}Temas;


Temas* temas_new();
void temas_delete();
Temas* temas_newConParametros(int id,char* nombre_Tema,char* artista,int idUsuario);

int temas_setId(Temas* this,int id);
int temas_getId(Temas* this,int* id);

int temas_setNombre_Tema(Temas* this,char* nombre_Tema);
int temas_getNombre_Tema(Temas* this,char* nombre_Tema);

int temas_setArtista(Temas* this,char* artista);
int temas_getArtista(Temas* this,char* artista);

int temas_setIdUsuario(Temas* this,int idUsuario);
int temas_getIdUsuario(Temas* this,int* idUsuario);


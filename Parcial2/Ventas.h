

typedef struct
{
    int idVenta;
    char FechaVenta[1024];
    int codigoProducto;
    float precioUnitario;
    char cuitCliente;
    int cantidadVentas;
}Venta;




Venta* Ventas_new();
void Ventas_delete();
Venta* Ventas_newConParametros(int idVenta,char* FechaVenta,int codigoProducto,int precioUnitario,char cuitCliente,int cantidadVentas);

int Ventas_setIdVenta(Venta* this,int idVenta);
int Ventas_getIdVenta(Venta* this,int* idVenta);

int Ventas_setFechaVenta(Venta* this,char* FechaVenta);
int Ventas_getFechaVenta(Venta* this,char* FechaVenta);

int Ventas_setCodigoProducto(Venta* this,int codigoProducto);
int Ventas_getCodigoProducto(Venta* this,int* codigoProducto);

int Ventas_setPrecioUnitario(Venta* this,int precioUnitario);
int Ventas_getPrecioUnitario(Venta* this,int* precioUnitario);

int Ventas_setCuitCliente(Venta* this,char cuitCliente);
int Ventas_getCuitCliente(Venta* this,char* cuitCliente);

int Ventas_setCantidadVentas(Venta* this,int cantidadVentas);
int Ventas_getCantidadVentas(Venta* this,int* cantidadVentas);


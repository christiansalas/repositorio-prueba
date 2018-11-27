

typedef struct
{
        int idVenta;
        char FechaVenta[1024];
        char codigoProducto[1024];
        int cantidadVentas;
        float precioUnitario;
        char cuitCliente[1024];
}Venta;




Venta* Ventas_new();
void Ventas_delete();
Venta* ventas_newConParametros(char* idVentas,char* fecha_venta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuit);

int Ventas_setIdVenta(Venta* this,int idVenta);
int Ventas_getIdVenta(Venta* this,int* idVenta);

int Ventas_setFechaVenta(Venta* this,char* FechaVenta);
int Ventas_getFechaVenta(Venta* this,char* FechaVenta);

int ventas_setCodigoProducto(Venta* this,char* codigoProducto);
int ventas_getCodigoProducto(Venta* this,char* codigoProducto);

int ventas_setPrecioUnitario(Venta* this,float precioUnitario);
int ventas_getPrecioUnitario(Venta* this,float* precioUnitario);


int Ventas_setCuitCliente(Venta* this,char* cuitCliente);
int Ventas_getCuitCliente(Venta* this,char* cuitCliente);

int Ventas_setCantidadVentas(Venta* this,int cantidadVentas);
int Ventas_getCantidadVentas(Venta* this,int* cantidadVentas);
int Ventas_calcularVentasLCD(void* pElement);
int Venta_VentasTotales(void*pElement);
int ventas_print(LinkedList* this);
int Ventas_calcularVentasMayor10000(void* pElement);
int Ventas_calcularVentasMayor20000(void* pElement);








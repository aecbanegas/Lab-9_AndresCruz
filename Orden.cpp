#include "Orden.h"
Orden::Orden(Negocios* neg, string cliente, string repartidor){
    negocio=neg;
    datoscliente=cliente;
    datosrepartidor=repartidor;
    estado=0;
    //0= en proceso 1= confirmado 2=cancelado
}
void Orden::cambioEstado(int est){
    estado=est;
}
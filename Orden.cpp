#include "Orden.h"
#include <sstream>
using std::stringstream;
Orden::Orden(Negocios* neg, int poscli,int pos,int posrepa){
    negocio=neg;
    poscliente=poscli;
    estado=0;
    posproducto=pos;
    posrepartidor=posrepa;
    //0= en proceso 1= confirmado 2=cancelado
}
void Orden::cambioEstado(int est){
    estado=est;
}
int Orden::getPosrepartidor(){
    return posrepartidor;
}
int Orden::getPoscliente(){
    return poscliente;
}
string Orden::toString(Cliente* cliente){
    stringstream imprimir;
    imprimir<<" Negocio: "<<negocio->toString()<<cliente->factura()<<" Producto: "<<negocio->getProductos()[posproducto]->toString();
    if(estado==0){
        imprimir<<" Estado: En Proceso";
    }else if(estado==1){
        imprimir<<" Estado: Confirmado";
    }else if(estado==2){
        imprimir<<" Estado: Cancelado";
    }
    return imprimir.str();
}
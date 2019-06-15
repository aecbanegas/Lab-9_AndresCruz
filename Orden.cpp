#include "Orden.h"
#include <sstream>
#include "Repartidor.h"
#include "Empleado.h"
using std::stringstream;
Orden::Orden(Negocios* neg, int poscli,int pos,int posrepa){
    negocio=neg;
    poscliente=poscli;
    estado=0;
    posproducto=pos;
    posrepartidor=posrepa;
    //0= en proceso 1= confirmado 2=cancelado
}
void Orden::aumOrdenes(vector<Persona*> personas){
    dynamic_cast<Cliente*>(personas[poscliente])->aumPedido();
    dynamic_cast<Repartidor*>(personas[posrepartidor])->aumOrden();
    for(int i=0;i<personas.size();i++){
        if(dynamic_cast<Empleado*>(personas[i])!=NULL){
            dynamic_cast<Empleado*>(personas[i])->aumOrden();
        }
    }
}
void Orden::cambioEstado(int est){
    estado=est;
}
int Orden::getEstado(){
    return estado;
}
int Orden::getPosrepartidor(){
    return posrepartidor;
}
int Orden::getPoscliente(){
    return poscliente;
}
string Orden::getNegocio(){
    return negocio->toString();
}
string Orden::getProducto(){
    return negocio->getProductos()[posproducto]->toString();
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
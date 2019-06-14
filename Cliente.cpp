#include "Cliente.h"
#include <sstream>
using std::stringstream;
Cliente::Cliente(string nom,string id,int ed,string dir,string tel,string tar){
    nombre=nom;
    identidad=id;
    edad=ed;
    dinero=0;
    direccion=dir;
    telefono=tel;
    tarjeta=tar;
    pedidos=0;
}
void Cliente::aumPedido(){
    pedidos++;
}
int Cliente::Ganancias(){
    return (pedidos*-100);
}
string Cliente::toString(){
    stringstream imprimir;
    return imprimir.str();
}
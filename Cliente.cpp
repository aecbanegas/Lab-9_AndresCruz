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
    imprimir<<"Cliente Nombre: "<<nombre<<" Identidad: "<<identidad<<" Edad: "<<edad<<"\nDireccion: "<<direccion<<" Telefono: "<<telefono<<" Tajeta: "<<tarjeta<<" Ganacias: "<<Ganancias()<<"\n";
    return imprimir.str();
}
string Cliente::factura(){
    stringstream imprimir;
    imprimir<<"Nombre: "<<nombre<<" Edad: "<<edad<<" Ubicacion: "<<direccion<<"\n";
    return imprimir.str();
}
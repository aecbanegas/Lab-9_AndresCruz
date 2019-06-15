#include "Facturar.h"
#include <iostream>
#include "Cliente.h"
using std::cout;
using std::endl;
Facturar::Facturar(){
    cont=0;
}
void Facturar::openFile(){
    stringstream nombre;
    nombre<<"Factura#"<<cont;
    if(file.is_open()){
        cout<<"Que pedos que paso!"<<endl;;
    }else{
        file.open(nombre.str());
    }
    cont++;
}
void Facturar::closeFile(){
    file.close();
}
void Facturar::crearFactura(Orden* orden,vector<Persona*>personas){
    openFile();
    file<<"**********************************************************\n";
    file<<dynamic_cast<Cliente*>(personas[orden->getPoscliente()])->factura();
    file<<orden->getNegocio();
    file<<orden->getProducto();
    if(orden->getEstado()==1){
        file<<"Estado de la orden::::::::::::::: CONFIRMADO\n";
    }else{
        file<<"Estado de la orden::::::::::::::::: CANCELADO\n";
    }
    file<<"**********************************************************\n";
    closeFile();
}
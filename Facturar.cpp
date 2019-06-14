#include "Facturar.h"
#include <iostream>
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
}
void Facturar::closeFile(){
    file.close();
}
void Facturar::crearFactura(Orden* orden){

}
#include "Empleado.h"
#include <sstream>
using std::stringstream;
Empleado::Empleado(string nom,string id,int ed,int hor,string loc){
    nombre=nom;
    identidad=id;
    edad=ed;
    dinero=0;
    horas=hor;
    local=loc;
    orden=0;
}
void Empleado::aumOrden(){
    orden++;
}
int Empleado::Ganancias(){
    return (30*orden+orden);
}
string Empleado::toString(){
    stringstream imprimir;
    imprimir<<"Empleado Nombre: "<<nombre<<" Identidad: "<<identidad<<" Edad: "<<edad<<"\nHoras de Trabajo: "<<horas<<" Local:"<<local<<" Ganacias: "<<Ganancias()<<"\n";
    return imprimir.str();
}
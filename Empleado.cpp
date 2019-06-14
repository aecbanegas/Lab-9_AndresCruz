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
    return (orden*40);
}
string Empleado::toString(){
    stringstream imprimir;
    return imprimir.str();
}
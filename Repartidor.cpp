#include "Repartidor.h"
#include <sstream>
using std::stringstream;
Repartidor::Repartidor(string nom,string id,int ed,string pla,string zon){
    nombre=nom;
    identidad=id;
    edad=ed;
    dinero=0;
    placa=pla;
    zona=zon;
    orden=0;
}
void Repartidor::aumOrden(){
    orden++;
}
int Repartidor::Ganancias(){
    return (orden*40);
}
string Repartidor::toString(){
    stringstream imprimir;
    imprimir<<"Repartidor Nombre: "<<nombre<<" Identidad: "<<identidad<<" Edad: "<<edad<<"\nPlaca: "<<placa<<" Zona: "<<zona<<" Ganacias: "<<Ganancias()<<"\n";
    return imprimir.str();
}
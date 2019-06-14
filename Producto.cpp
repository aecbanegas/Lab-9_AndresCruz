#include "Producto.h"
#include <sstream>
using std::stringstream;
Producto::Producto(string nom, bool tip){
    nombre=nom;
    tipo=tip;
}
string Producto::toString(){
    stringstream imprimir;
    return imprimir.str();
}
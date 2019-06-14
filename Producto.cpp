#include "Producto.h"
#include <sstream>
using std::stringstream;
Producto::Producto(string nom, bool tip){
    nombre=nom;
    tipo=tip;//true=comestible false=no comestible
}
string Producto::toString(){
    stringstream imprimir;
    imprimir<<nombre;
    if(tipo){
        imprimir<<" Comestible";
    }else{
        imprimir<<" No Comestible";
    }
    return imprimir.str();
}
#ifndef ORDEN_H
#define ORDEN_H
#include "Negocios.h"
#include <string>
using std::string;
class Orden{
    private:
        Negocios* negocio;
        string datoscliente;
        string datosrepartidor;
        int estado;
    public:
        Orden(Negocios*,string,string);
        void cambioEstado(int);

};
#endif
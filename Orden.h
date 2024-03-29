#ifndef ORDEN_H
#define ORDEN_H
#include "Negocios.h"
#include "Cliente.h"
#include "Persona.h"
#include <string>
using std::string;
class Orden{
    private:
        Negocios* negocio;
        int poscliente;
        int posrepartidor;
        int posproducto;
        int estado;
    public:
        Orden(Negocios*,int,int,int);
        void cambioEstado(int);
        int getPosrepartidor();
        int getPoscliente();
        string getNegocio();
        string getProducto();
        int getEstado();
        string toString(Cliente*);
        void aumOrdenes(vector<Persona*>);
};
#endif
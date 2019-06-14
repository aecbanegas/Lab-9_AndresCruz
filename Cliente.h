#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
class Cliente:public Persona{
    private:
        string direccion;
        string telefono;
        string tarjeta;
        int pedidos;
    public:
        Cliente(string,string,int,string,string,string);
        void aumPedido();
        virtual string toString();
        virtual int Ganancias();
        
};
#endif
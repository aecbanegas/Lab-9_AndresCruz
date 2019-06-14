#ifndef REPARTIDOR_H
#define REPARTIDOR_H
#include "Persona.h"
class Repartidor:public Persona{
    private:
        string placa;
        string zona;
        int orden;
    public:
        Repartidor(string,string,int,string,string);
        void aumOrden();
        virtual string toString();
        virtual int Ganancias();
        
};
#endif
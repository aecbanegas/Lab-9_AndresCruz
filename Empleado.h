#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
class Empleado:public Persona{
    private:
        int horas;
        string local;
        int orden;
    public:
        Empleado(string,string,int,int,string);
        void aumOrden();
        virtual string toString();
        virtual int Ganancias();
        
};
#endif
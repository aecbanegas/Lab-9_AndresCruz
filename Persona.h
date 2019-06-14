#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using std::string;
class Persona{
    protected:
        string nombre;
        string identidad;
        int edad;
        int dinero;
    public:
        virtual int Ganancias()=0;
        virtual string toString()=0;
};
#endif
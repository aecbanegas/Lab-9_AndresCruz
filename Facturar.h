#ifndef FACTURAR_H
#define FACTURAR_H
#include <fstream>
#include "Orden.h"
#include <sstream>
#include <string>
#include "Persona.h"
using std::string;
using std::stringstream;
using std::ofstream;
class Facturar{
    private:
        ofstream file;
        int cont;
    public:
        void openFile();
        void closeFile();
        void crearFactura(Orden*,vector<Persona*>);
        Facturar();
};
#endif
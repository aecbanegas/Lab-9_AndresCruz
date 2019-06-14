#ifndef NEGOCIOS_H
#define NEGOCIOS_H
#include "Producto.h"
#include <vector>
#include <string>
using namespace std;
class Negocios{
    private:
        string nombre;
        string ubicacion;
        int locales;
        vector<Producto> productos;
    public:
        Negocios(string, string,int,vector<Producto>);
        string toString();
        vector<Producto> getProductos();
};
#endif
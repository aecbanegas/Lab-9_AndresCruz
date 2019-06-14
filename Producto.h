#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using std::string;
class Producto{
    private:
        string nombre;
        bool tipo;
    public:
        Producto(string,bool);
        string toString();
};
#endif
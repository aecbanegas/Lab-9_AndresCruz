#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Persona.h"
#include "Cliente.h"
#include "Repartidor.h"
#include "Empleado.h"
#include "Negocios.h"
#include "Orden.h"
#include "Producto.h"
#include "Facturar.h"
#include <vector>
#include <string>
using std::vector;
using std::string;
int main(){
    vector<Negocios*> negocios;
    vector<Persona*> personas;
    vector<Orden*> procesando;
    vector<Orden*> terminadas;
    Facturar* archivar=new Facturar();
    int opcmenu=0;
    while(opcmenu!=11){
        cout<<"     Menu Hugo"<<endl
            <<"1. Crear Personas"<<endl
            <<"2. Crear Negocios"<<endl
            <<"3. Listar Personas"<<endl
            <<"4. Listar Negocios"<<endl
            <<"5. Ordenar"<<endl
            <<"6. Listar Ordenes"<<endl
            <<"7. Confirmar o cancelar orden"<<endl
            <<"8. Listar Productos de Negocio"<<endl
            <<"9. Eliminar Persona"<<endl
            <<"10. Eliminar Negocio"<<endl
            <<"11. Salir "<<endl
            <<"Ingrese una opcion: "<<endl;
        cin>>opcmenu;
        switch (opcmenu){
            case 1:
                {
                    int opccrear=0;                    
                    cout<<"Bienvenido"<<endl
                        <<"1. Cliente"<<endl
                        <<"2. Repartidor"<<endl
                        <<"3. Empleado"<<endl
                        <<"Ingrese que usuario desea crear:"<<endl;
                    cin>>opccrear;
                    switch (opccrear){
                        case 1:
                        {//cliente
                            string nombre,identidad,direccion,telefono,tarjeta;
                            int edad;
                            cout<<"Ingrese su nombre:"<<endl;
                            cin>>nombre;
                            cout<<"Ingrese su identidad:"<<endl;
                            cin>>identidad;
                            cout<<"Ingrese su edad: "<<endl;
                            cin>>edad;
                            cout<<"Ingrese su direccion: "<<endl;
                            getline(cin,direccion);
                            getline(cin,direccion);
                            cout<<"Ingrese su telefono: "<<endl;
                            cin>>telefono;
                            cout<<"Ingrese su numero de tarjeta: "<<endl;
                            getline(cin,tarjeta);
                            getline(cin,tarjeta);
                            personas.push_back(new Cliente(nombre,identidad,edad,direccion,telefono,tarjeta));
                            cout<<"Se ha agregado de manera exitosa!"<<endl;
                        }
                        break;
                        case 2:
                        {//repartidor
                            string nombre,identidad,placa,zona;
                            int edad;
                            cout<<"Ingrese su nombre:"<<endl;
                            cin>>nombre;
                            cout<<"Ingrese su identidad:"<<endl;
                            cin>>identidad;
                            cout<<"Ingrese su edad: "<<endl;
                            cin>>edad;
                            cout<<"Ingrese su placa: "<<endl;
                            getline(cin,placa);
                            getline(cin,placa);
                            cout<<"Ingrese su zona de entrega: "<<endl;
                            cin>>zona;
                            personas.push_back(new Repartidor(nombre,identidad,edad,placa,zona));
                            cout<<"Se ha agregado de manera exitosa!"<<endl;
                        }
                        break;
                        case 3:
                        {//empleado
                            string nombre,identidad,local;
                            int edad,horas;
                            cout<<"Ingrese su nombre:"<<endl;
                            cin>>nombre;
                            cout<<"Ingrese su identidad:"<<endl;
                            cin>>identidad;
                            cout<<"Ingrese su edad: "<<endl;
                            cin>>edad;
                            cout<<"Ingrese cuantas horas trabaja: "<<endl;
                            cin>>horas;
                            cout<<"Ingrese nombre del local en el que trabaja: "<<endl;
                            cin>>local;
                            personas.push_back(new Empleado(nombre,identidad,edad,horas,local));
                            cout<<"Se ha agregado de manera exitosa!"<<endl;
                        }
                        break;
                        default:
                        {
                            cout<<"Ha ingresado una opcion invalida! Intente Nuevamente!"<<endl;
                        }
                        break;
                    }
                }
                break;
            case 2:
                {
                    string nombre,ubicacion;
                    int locales;
                    vector<Producto*> productos;
                    cout<<"Ingrese el nombre del negocio:"<<endl;
                    cin>>nombre;
                    cout<<"Ingrese la ubicacion del negocio: "<<endl;
                    getline(cin,ubicacion);
                    getline(cin,ubicacion);
                    cout<<"Ingrese el numero de locales disponibles: "<<endl;
                    cin>>locales;
                    bool agregarmas=true;
                    string nomproducto;
                    int resp;
                    bool tipo;
                    while(agregarmas){//agregar productos
                        cout<<"Ingrese el nombre del producto: "<<endl;
                        cin>>nomproducto;
                        cout<<"Ingrese si es comestible o no: 1= Comestible 0=No comestible"<<endl;
                        cin>>resp;
                        while(resp<0||resp>1){
                            cout<<"Ingrese si es comestible o no: 1= Comestible 0=No comestible"<<endl;
                            cin>>resp;
                        }
                        if (resp==1){//true comestible
                            tipo=true;
                        }else{
                            tipo=false;
                        }
                        productos.push_back(new Producto(nomproducto,tipo));
                        char seguir;
                        cout<<"Desea agregar otro producto: s/n"<<endl;
                        cin>>seguir;
                        if(seguir=='n'){
                            agregarmas=!agregarmas;
                        }
                    }
                    negocios.push_back(new Negocios(nombre,ubicacion,locales,productos));
                    cout<<"Se ha agregado el Negocio con exito!"<<endl;
                }
                break;
            case 3:
                {
                    for (int i = 0; i < personas.size(); i++)
                    {
                        cout<<"Posicion "<<i<<" Tipo: "<<personas[i]->toString();
                    }
                }
                break;
            case 4:
                {
                    for (int i = 0; i < negocios.size(); i++)
                    {
                        cout<<"Posicion "<<i<<negocios[i]->toString();
                    }
                    
                }
                break;
            case 5:
                {
                   int posnegocio,poscliente,posrepartidor,posproducto; 
                   cout<<"Ingrese la posicion en que se ubica negocio: "<<endl;
                   cin>>posnegocio;
                    if (posnegocio<0||posnegocio>=negocios.size())
                    {
                        cout<<"No existe el negocio seleccionado!"<<endl;
                    }else{
                        cout<<"Ingrese la posicion en que se ubica el cliente: "<<endl;
                        cin>>poscliente;
                        if(!(poscliente<0||poscliente>=personas.size())){
                            if ((dynamic_cast<Cliente*>(personas[posnegocio])!=NULL))
                            {
                                cout<<"Ingrese la posicion del repartidor:"<<endl;
                                cin>>posrepartidor;
                                if(posrepartidor<0||posrepartidor>=personas.size()){
                                    cout<<"La posicion no existe!"<<endl;
                                }else{
                                    if(dynamic_cast<Repartidor*>(personas[posrepartidor])!=NULL){
                                        cout<<"Ingrese la posicion del producto: "<<endl;
                                        cin>>posproducto;
                                        if(posproducto<0||posproducto>=negocios[posnegocio]->getProductos().size()){
                                            cout<<"El producto ingresado no existe!"<<endl;
                                        }else{
                                            procesando.push_back(new Orden(negocios[posnegocio],poscliente,posproducto,posrepartidor));
                                        }
                                    }else{
                                        cout<<"La persona seleccionada no es repartidor!"<<endl;
                                    }
                                }
                            }else{
                                cout<<"La persona no es cliente!"<<endl;
                            }
                        }else{
                            cout<<"No existe la persona indicada!"<<endl;
                        }
                    }
                }
                break;
            case 6:
                {
                    cout<<"Ordenes en proceso: "<<endl;
                    for (int i = 0; i < procesando.size(); i++)
                    {
                        cout<<"Posicion "<<i<<" "<<procesando[i]->toString(dynamic_cast<Cliente*>(personas[procesando[i]->getPoscliente()]))<<endl;
                    }
                    cout<<"Ordenes terminadas: "<<endl;
                    for (int i = 0; i < terminadas.size(); i++)
                    {
                        cout<<"Posicion "<<i<<" "<<terminadas[i]->toString(dynamic_cast<Cliente*>(personas[terminadas[i]->getPoscliente()]))<<endl;
                    }
                    
                    
                }
                break;
            case 7:
                {
                    int posorden;
                    cout<<"Ingrese la posicion de la orden:"<<endl;
                    cin>>posorden;
                    if(posorden<0||posorden>=procesando.size()){
                        cout<<"No existe esa posicion!"<<endl;
                    }else{
                        char decision;
                        cout<<"Desea confirmar o cancelar la orden: s=confirmar c=cancelar"<<endl;
                        cin>>decision;
                        if(decision=='s'){
                            terminadas.push_back(procesando[posorden]);
                            procesando.erase(procesando.begin()+posorden);
                            terminadas[terminadas.size()-1]->cambioEstado(1);
                            archivar->crearFactura(terminadas[terminadas.size()-1],personas);
                            terminadas[terminadas.size()-1]->aumOrdenes(personas);
                        }else if(decision=='c'){
                            terminadas.push_back(procesando[posorden]);
                            procesando.erase(procesando.begin()+posorden);
                            terminadas[terminadas.size()-1]->cambioEstado(2);
                            archivar->crearFactura(terminadas[terminadas.size()-1],personas);
                            terminadas[terminadas.size()-1]->aumOrdenes(personas);
                        }else{
                            cout<<"Intentelo de nuevo!"<<endl;
                        }
                    }
                }
                break;
            case 8:
                {
                    if(!negocios.empty()){
                        int posnegocio;
                        cout<<"Ingrese la posicion del negocio: "<<endl;
                        cin>>posnegocio;
                        if(posnegocio<0||posnegocio>=negocios.size()){
                            cout<<"La posicion no existe, intente de nuevo!"<<endl;
                        }else{
                            vector<Producto*>productos=negocios[posnegocio]->getProductos();
                            for (int i = 0; i < productos.size(); i++)
                            {
                                cout<<"Posicion "<<i<<" "<<productos[i]->toString()<<endl;
                            }
                        }
                    }else{
                        cout<<"No existen negocios aun!"<<endl;
                    }
                }
                break;
            case 9:
                {
                    int pospersona;
                    cout<<"Ingrese la posicion de la persona que desea eliminar: "<<endl;
                    cin>>pospersona;
                    if((pospersona<0||pospersona>=personas.size())){
                        cout<<"Posicion no existe, intente de nuevo!"<<endl;
                    }else{
                        delete personas[pospersona];
                        personas.erase(personas.begin()+pospersona);
                        cout<<"Se elimino con exito!"<<endl;
                    }
                }
                break;
            case 10:
                {
                    int posnegocio;
                    cout<<"Ingrese la posicion de el negocio que desea eliminar: "<<endl;
                    cin>>posnegocio;
                    if((posnegocio<0||posnegocio>=negocios.size())){
                        cout<<"Posicion no existe, intente de nuevo!"<<endl;
                    }else{
                        delete negocios[posnegocio];
                        negocios.erase(negocios.begin()+posnegocio);
                        cout<<"Se elimino con exito!"<<endl;
                    }
                }
                break;
        }
    }
    //liberar memoria
    for (int i = 0; i < negocios.size(); i++)
    {
        delete negocios[i];
    }
    for (int i = 0; i < personas.size(); i++)
    {
        delete personas[i];
    }
    for (int i = 0; i < procesando.size(); i++)
    {
        delete procesando[i];
    }
    for (int i = 0; i < terminadas.size(); i++)
    {
        delete terminadas[i];
    }
    return 0;
}
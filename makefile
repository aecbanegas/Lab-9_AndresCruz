Main: Main.o Cliente.o Repartidor.o Empleado.o Negocios.o Producto.o Orden.o Facturar.o
	g++ Main.o Cliente.o Repartidor.o Empleado.o Negocios.o Producto.o Orden.o Facturar.o -o Ejecutable
Main.o: Main.cpp
	g++ -c Main.cpp
Cliente.o: Cliente.cpp Cliente.h
	g++ -c Cliente.cpp
Repartidor.o: Repartidor.cpp Repartidor.h
	g++ -c Repartidor.cpp
Empleado.o: Empleado.cpp Empleado.h
	g++ -c Empleado.cpp
Negocios.o: Negocios.cpp Negocios.h
	g++ -c Negocios.cpp
Producto.o: Producto.cpp Producto.h
	g++ -c Producto.cpp
Orden.o: Orden.cpp Orden.h
	g++ -c Orden.cpp
Facturar.o: Facturar.cpp Facturar.h
	g++ -c Facturar.cpp
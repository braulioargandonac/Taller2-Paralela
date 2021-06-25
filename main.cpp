#include "Venta.h"
#include "Funciones.h"

//Ir a la carpeta del programa en la terminal y ejecutar lo siguiente:
//1) make
//2) ./dist/programa estudiantes.csv

int main(int argc, char** argv) {
    std::vector<Venta> V;

    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        

        if (lectura) {
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<std::string> datos = ObtenerDatos(linea);
                if(datos[0]!="reate"){
                    Venta V;
                    std::vector<std::string> fecha1=fecha(datos[0],'-');
                    std::vector<std::string> fecha2=fecha(fecha1[2],' ');

                    V.SetAno(stoi(fecha1[0]));
                    V.SetMes(stoi(fecha1[1]));
                    V.SetDia(stoi(fecha2[0]));
                    V.SetCantidad(stoi(datos[2]));
                    V.SetMonto(stoi(datos[3]));

                    fecha1.clear();
                    fecha2.clear();
                }
                datos.clear();
            }

            std::cout<<std::endl<<"PROGRAMA EJECUTADO CORRECTAMENTE"<<std::endl;
            std::cout<<"SE HAN GENERADO LOS RESPECTIVOS ARCHIVOS"<<std::endl;
            Participantes();
        }else{
            std::cout<<std::endl<<"NO HA INGRESADO NINGUN ARCHIVO VALIDO"<<std::endl;
            Participantes();
        }
    }else{
        std::cout<<std::endl<<"NO HA INGRESADO NINGUN ARCHIVO"<<std::endl;
        Participantes();
    }
    return EXIT_SUCCESS;
}


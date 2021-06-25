#include "Funciones.h"

void Participantes() {
    std::cout << std::endl << "Creado por:" << std::endl;
    std::cout << std::endl << "- Braulio Argandoña"  << std::endl;
    std::cout << std::endl << "- Kevin Salinas"  << std::endl;
    std::cout << std::endl << "- Rodrigo Aguirre"  << std::endl<< std::endl;
}

std::vector<std::string> ObtenerDatos(std::string fila){
    std::vector<std::string> arreglo;
    std::stringstream ss(fila);
    std::string item;

    while (std::getline(ss, item, ';')){
        std::string dato=item.c_str();
        dato.erase(dato.begin());
        dato.pop_back();
        arreglo.push_back(dato);
    }

    return arreglo;
}

std::vector<std::string> fecha(std::string fecha1, char del){
    //2020-11-11 15:07:32.361
    std::vector<std::string> arreglo;
    std::stringstream ss(fecha1);
    std::string item;

    while (std::getline(ss, item, del)){
        std::string dato=item.c_str();
        arreglo.push_back(dato);
    }

    return arreglo;
}
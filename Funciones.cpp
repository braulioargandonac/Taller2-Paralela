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

std::vector<Venta> dia(std::vector<Venta> Ventas){
    std::vector<Venta> V;
    int monto=0;
    int cont=1;
    for(int i=0; i<=int(Ventas.size()); i++){
        if(i!=0){
            if(Ventas[i].GetAno()==Ventas[i-1].GetAno()){
                if(Ventas[i].GetMes()==Ventas[i-1].GetMes()){
                    if(Ventas[i].GetDia()==Ventas[i-1].GetDia()){
                        monto=monto+Ventas[i].GetMonto()*Ventas[i].GetCantidad();
                        cont++;
                    }else{
                        Ventas[i-1].SetTotal(monto);
                        Ventas[i-1].SetCantVentas(cont);
                        monto=Ventas[i].GetMonto();
                        cont=1;
                        V.push_back(Ventas[i-1]);
                    }
                }else{
                    Ventas[i-1].SetTotal(monto);
                    Ventas[i-1].SetCantVentas(cont);
                    monto=Ventas[i].GetMonto();
                    cont=1;
                    V.push_back(Ventas[i-1]);
                }
            }else{
                Ventas[i-1].SetTotal(monto);
                Ventas[i-1].SetCantVentas(cont);
                monto=Ventas[i].GetMonto();
                cont=1;
                V.push_back(Ventas[i-1]);
            }
        }else{
            monto=Ventas[i].GetMonto();
        }
    }
    return V;
}

int promVentas(std::vector<Venta> Ventas){
    int total=0;
    int cont=0;
    for(int i=0; i<int(Ventas.size()); i++){
        total=total+Ventas[i].GetTotal();
        cont++;
    }
    return total/cont;
}
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
            monto=Ventas[i].GetMonto()*Ventas[i].GetCantidad();
        }
    }
    return V;
}

/** Minimos Cuadrados **/
int SumCantDias(std::vector<Venta> Ventas){
    int cont = 0;
    double cont2 = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        cont++;
        cont2 += cont;
    }
    return cont2;
}

int CantDiasCuad(std::vector<Venta> Ventas){
    int cont = 0;
    double cont2 = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        cont++;
        cont2 += cont;
    }
    return cont2 * cont2;
}

int SumCantDiasCuad(std::vector<Venta> Ventas, int cant_dia){
    int total = 0, aux = 0;
    for(int i=0; i<int(Ventas.size()); i++){
        aux = pow(cant_dia, 2);
        total += aux;
    }
    return total;
}

int SumVentas(std::vector<Venta> Ventas){
    double total = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        total = total + Ventas[i].GetCantVentas();
    }
    return total;
}

int SumCantDias_xVentas(std::vector<Venta> Ventas, int sum_dias, int cant_dias){
    int total = 0, aux = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = sum_dias * cant_dias;
        total += aux;
    }
    return total;
}

double Pendiente(int Sum_CantDias, int cantdias_cuad, int dias_cuad, int cant_venta, int CantxVenta){
    double M = 0;
    M = (CantxVenta - (((Sum_CantDias) * (cant_venta)) / 199)) / (cantdias_cuad - (dias_cuad) / 199);
    return M;
}
/*int PromVentas(std::vector<Venta> Ventas){
    int total=0;
    int cont=0;
    for(int i=0; i<int(Ventas.size()); i++){
        total=total+Ventas[i].GetTotal();
        cont++;
    }
    std::cout<<"numerador: "<<total<< "  Denominador: "<<cont<<std::endl;
    std::cout<< "total " <<Ventas.size() <<std::endl;
    return total/cont;
}*/


/** Regresion lineal **/
double PromSumCantDias(std::vector<Venta> Ventas){
    int cont = 0;
    double contaux = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        cont++;
        contaux = contaux + cont;
    }
    contaux = contaux / int(Ventas.size());
    return contaux;
}

double PromSumVentas(std::vector<Venta> Ventas){
    double total = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        total = total + Ventas[i].GetCantVentas();
    }
    total = total / int(Ventas.size());
    return total;
}

double SumCuadrado(std::vector<Venta>Ventas, double promedio){
    double contsum = 0;
    double aux = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = i + 1 - promedio;
        aux = pow(aux,2);
        contsum = contsum + aux;
    }
    return contsum;
}

long double SumCuadradoVentas(std::vector<Venta>Ventas, double promedio){
    long double contsum = 0;
    double aux = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = Ventas[i].GetCantVentas() - promedio;
        aux = pow(aux,2);
        contsum = contsum + aux;
    }
    return contsum;
}

double MultSumas(std::vector<Venta>Ventas, double promedio1, double promedio2){
    double sum = 0;
    int aux = 0;
    int aux2 = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = i + 1 - promedio1;
        aux2 = Ventas[i].GetCantVentas() - promedio2;
        sum = sum + (aux * aux2);
    }
    return sum;
}

double covarianza (double dato, int largo){
    double aux = 0;
    aux = dato / largo;
    return aux;
}

double Desviacion_Estandar(double sumprom, int largo){
    double aux = 0;
    aux = sumprom / largo;
    aux = sqrt(aux);
    return aux;
}

double calculob(double covarianza, double desviacion){
    double aux = 0;
    aux = covarianza/pow(desviacion,2);
    return aux;
}

double calculoa(double prom1, double prom2, double calculob){
    double aux = 0;
    aux = prom1 - (prom2 * calculob);
    return aux;
}

void printformula(double A, double B){
    std::cout << "La formula para la regresion lineal es: " << std::endl << "Y = " << A << " + " << B <<"* X (Cantidad de dias)" << std::endl;
}

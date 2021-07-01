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
        std::string dato = item.c_str();
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
        std::string dato = item.c_str();
        arreglo.push_back(dato);
    }

    return arreglo;
}

std::vector<Venta> dia(std::vector<Venta> Ventas){
    std::vector<Venta> V;
    int monto = 0;
    int cont = 1;
    for(int i = 0; i <= int(Ventas.size()); i++){
        if(i != 0){
            if(Ventas[i].GetAno() == Ventas[i-1].GetAno()){
                if(Ventas[i].GetMes() == Ventas[i-1].GetMes()){
                    if(Ventas[i].GetDia() == Ventas[i-1].GetDia()){
                        monto = monto+Ventas[i].GetMonto()*Ventas[i].GetCantidad();
                        cont++;
                    }else{
                        Ventas[i-1].SetTotal(monto);
                        Ventas[i-1].SetCantVentas(cont);
                        monto = Ventas[i].GetMonto();
                        cont = 1;
                        V.push_back(Ventas[i-1]);
                    }
                }else{
                    Ventas[i-1].SetTotal(monto);
                    Ventas[i-1].SetCantVentas(cont);
                    monto = Ventas[i].GetMonto();
                    cont = 1;
                    V.push_back(Ventas[i-1]);
                }
            }else{
                Ventas[i-1].SetTotal(monto);
                Ventas[i-1].SetCantVentas(cont);
                monto = Ventas[i].GetMonto();
                cont = 1;
                V.push_back(Ventas[i-1]);
            }
        }else{
            monto = Ventas[i].GetMonto()*Ventas[i].GetCantidad();
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

int SumCantDiasCuad(std::vector<Venta> Ventas){
    int total = 0, aux = 0;
    for(int i=0; i<int(Ventas.size()); i++){
        aux = pow((i+1), 2);
        total += aux;
    }
    return total;
}

int SumVentas(std::vector<Venta> Ventas){
    int total = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        total = total + Ventas[i].GetCantVentas();
    }
    return total;
}

int SumCantDias_xVentas(std::vector<Venta> Ventas){
    int total = 0, aux = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = (i+1) * Ventas[i].GetCantVentas();
        total += aux;
    }
    return total;
}

double Pendiente(double Sum_CantDias, double cantdias_cuad, double dias_cuad, double cant_venta, double CantxVenta){
    double M = 0;
    M = (CantxVenta - (((Sum_CantDias) * (cant_venta)) / 199)) / (cantdias_cuad - (dias_cuad) / 199);
    return M;
}

double intercepcion(double CantxVenta, double Sum_CantDias, double cantdias_cuad, double dias_cuad, double cant_venta){
    double b = 0;
    b = ((199 * CantxVenta) - (Sum_CantDias * cant_venta)) / ((199 * dias_cuad) - cantdias_cuad);
    return b;
}

void MostrarMinimo(double pendiente, double intercepto){
    std::cout << "La formula para los minimos cuadrados es: " << std::endl << "Y = " << pendiente << " * (Cantidad de dias)" << " - " << intercepto << std::endl;
}

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

/** Funcion exponencial **/


//Sum ( X*Ln(y) )
double SumCantLN(std::vector<Venta>Ventas){
    double contsum = 0;
    double aux = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = (i + 1) * log(Ventas[i].GetCantVentas());
        contsum = contsum + aux;
    }
    return contsum;
}

//Sum (X) * Sum ( Ln(Y) )
double SumCantSumLN(std::vector<Venta>Ventas){
    double aux = 0;
    int aux1 = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        aux = aux + log(Ventas[i].GetCantVentas());
        aux1 = aux1 + (i+1);
    }
    return aux * aux1;
}

//Prom Ln(Y)
double PromCantVentasLn(std::vector<Venta> Ventas){
    double total = 0;
    for(int i = 0; i < int(Ventas.size()); i++){
        total = total + log(Ventas[i].GetCantVentas());
    }
    total = total / int(Ventas.size());
    return total;
}

//B de =>  Y = A * e^BX
double ExpB(std::vector<Venta> Venta){
    double num = 0, den = 0;
    num = (int(Venta.size()) * SumCantLN(Venta)) - SumCantSumLN(Venta);
    den = (int(Venta.size()) * SumCantDiasCuad(Venta)) - CantDiasCuad(Venta);
    return num / den;
}

//Prom(Ln(Y)) - B * Prom X
double ExpA(std::vector<Venta> Venta){
    double resultado = 0;
    resultado = PromCantVentasLn(Venta) - (ExpB(Venta) * PromSumVentas(Venta));
    return exp(resultado);
}

void printformula2(double A, double B){
    std::cout << "La formula para la funcion exponencial es: " << std::endl << "Y = " << A << " * e^( " << B <<" * (Cantidad de dias))" << std::endl;
}

void funciones(std::vector<Venta> VentasDia){
    /** Regresion lineal **/
    double cant_dias = PromSumCantDias(VentasDia);
    double total_ventas = PromSumVentas(VentasDia);
    double Sum_Cant_Dias = SumCuadrado(VentasDia, cant_dias);
    double Mult_Sum_DiasVentas = MultSumas(VentasDia, cant_dias, total_ventas);
    double Covar = covarianza(Mult_Sum_DiasVentas, int(VentasDia.size()));
    double Desv = Desviacion_Estandar(Sum_Cant_Dias, int(VentasDia.size()));
    double calculo_B = calculob(Covar, Desv);
    double calculo_A = calculoa(total_ventas, cant_dias, calculo_B);


    /** Minimos Cuadrados **/
    int Sum_CantDias = SumCantDias(VentasDia);
    int cantdias_cuad = CantDiasCuad(VentasDia);
    int dias_cuad = SumCantDiasCuad(VentasDia);
    int cant_venta = SumVentas(VentasDia);
    int CantxVenta = SumCantDias_xVentas(VentasDia);
    double pendiente = Pendiente(Sum_CantDias, cantdias_cuad, dias_cuad, cant_venta, CantxVenta);
    double intercepto = intercepcion(CantxVenta, Sum_CantDias, cantdias_cuad, dias_cuad, cant_venta);


    printformula(calculo_A, calculo_B);
    MostrarMinimo(pendiente, intercepto);
    printformula2(ExpA(VentasDia), ExpB(VentasDia));
}
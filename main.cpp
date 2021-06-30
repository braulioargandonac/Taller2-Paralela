#include "Venta.h"
#include "Funciones.h"

//Ir a la carpeta del programa en la terminal y ejecutar lo siguiente:
//1) make
//2) ./dist/programa estudiantes.csv

int main(int argc, char** argv) {
    std::vector<Venta> Ventas;
    std::vector<Venta> VentasDia;

    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        Venta V;
        

        if (lectura) {
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<std::string> datos = ObtenerDatos(linea);
                if(datos[0]!="reate"){
                    std::vector<std::string> fecha1=fecha(datos[0],'-');
                    std::vector<std::string> fecha2=fecha(fecha1[2],' ');

                    V.SetAno(stoi(fecha1[0]));
                    V.SetMes(stoi(fecha1[1]));
                    V.SetDia(stoi(fecha2[0]));
                    V.SetCantidad(stoi(datos[2]));
                    V.SetMonto(stoi(datos[3]));

                    fecha1.clear();
                    fecha2.clear();
                    Ventas.push_back(V);
                }
                datos.clear();
            }
            VentasDia=dia(Ventas);

            //VENTASDIA ES EL VECTOR CON LAS FECHAS AGRUPADAS
            //PARA VER EL MONTO DE UN DIA ES GETTOTAL
            //GETMONTO NO APLICA PARA VENTASDIA, PERO SI PARA EL VECTOR VENTAS
            //GETCANTVENTAS ES LA CANTIDAD DE VENTAS EN UN DIA
            //GETCANT ES LA CANTIDAD DE UNA COMPRA Y NO APLICA TAMPOCO PARA VENTASDIAS
            
            //int prom_ventas=promVentas(VentasDia);
            //std::cout<<"Promedio de las ventas: "<<prom_ventas<<std::endl;
            for(int i=0; i<int(VentasDia.size()); i++){
                //std::cout<<VentasDia[i].GetCantVentas()<<"-"<<VentasDia[i].GetDia()<<"-"<<VentasDia[i].GetTotal()<<std::endl;
            }

            double cant_dias = PromSumCantDias(VentasDia);
            std::cout<<"El promedio de la sumatoria de la cantidad de dias es: "<< cant_dias << std::endl;

            double total_ventas = PromSumVentas(VentasDia);
            std::cout<<"El promedio de la sumatoria de la cantidad de ventas: " << total_ventas << std::endl;

            double Sum_Cant_Dias = SumCuadrado(VentasDia,cant_dias);
            std::cout<<"la sumatoria al cuadrado es: " << Sum_Cant_Dias << std::endl;

            long double Sum_Cant_Ventas = SumCuadradoVentas(VentasDia,total_ventas);
            std::cout<<"la sumatoria al cuadrado es (Dias): " << Sum_Cant_Ventas << std::endl;

            double Mult_Sum_DiasVentas = MultSumas(VentasDia, cant_dias,total_ventas);
            std::cout<<"la sumatoria de la multiplicacion es: " << Mult_Sum_DiasVentas << std::endl;

            double Covar = covarianza(Mult_Sum_DiasVentas,int(VentasDia.size()));
            std::cout<<"la covarianza es: " << Covar << std::endl;

            double Desv = Desviacion_Estandar(Sum_Cant_Dias,int(VentasDia.size()));
            std::cout<<"la desviacion estandar de X es: " << Desv << std::endl;

            double calculo_B=calculob(Covar,Desv);
            std::cout<<"B es igual a: " << calculo_B << std::endl;

            double calculo_A = calculoa(total_ventas,cant_dias,calculo_B);
            std::cout<<"A es igual a: "<<calculo_A<<std::endl;
            
            printformula(calculo_A,calculo_B);

            std::cout<<std::endl<<"PROGRAMA EJECUTADO CORRECTAMENTE"<<std::endl;
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


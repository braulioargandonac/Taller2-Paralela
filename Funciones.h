#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Venta.h"
#include <math.h>

/**
 * Despliega los participantes del equipo de trabajo
 */
void Participantes(); //Función que muestra los participantes del grupo

/**
 * @param fila una línea del archivo
 * @return vector con los datos del archivo csv
 */
std::vector<std::string> ObtenerDatos(std::string fila);

std::vector<std::string> fecha(std::string, char);

std::vector<Venta> dia(std::vector<Venta>);

/*double PromVentas(std::vector<Venta>);*/

double PromSumCantDias(std::vector<Venta>);

double PromSumVentas(std::vector<Venta>);

double SumCuadrado(std::vector<Venta>,double);

long double SumCuadradoVentas(std::vector<Venta>, double );

double MultSumas(std::vector<Venta>,double ,double );

double covarianza (double , int );

double Desviacion_Estandar(double , int );

double calculob(double ,double );

double calculoa(double , double , double );

void printformula(double , double );

#endif // FUNCIONES_H_INCLUDED

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

/** Minimos Cuadrados **/
int SumCantDias(std::vector<Venta>);

int CantDiasCuad(std::vector<Venta>);

int SumCantDiasCuad(std::vector<Venta>, int);

int SumVentas(std::vector<Venta>);

int SumCantDias_xVentas(std::vector<Venta>, int, int);

double Pendiente(int, int, int, int, int);

double intercepcion(double, double, double);

void MostrarMinimo(double, double);

/** Regresion lineal **/
double PromSumCantDias(std::vector<Venta>);

double PromSumVentas(std::vector<Venta>);

double SumCuadrado(std::vector<Venta>, double);

long double SumCuadradoVentas(std::vector<Venta>, double);

double MultSumas(std::vector<Venta>, double, double);

double covarianza (double, int);

double Desviacion_Estandar(double, int);

double calculob(double, double);

double calculoa(double, double, double);

void printformula(double, double);

#endif // FUNCIONES_H_INCLUDED

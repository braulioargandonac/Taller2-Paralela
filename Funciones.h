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

/**
 * @param fila una linea del archivo
 * @param recibe un delimitador
 * @return un vector segmentado por el delimitador
 */
std::vector<std::string> fecha(std::string, char);

/**
 * @param vector de tipo clase Venta
 * @return los dias del Vector Venta
 */
std::vector<Venta> dia(std::vector<Venta>);


/** Minimos Cuadrados **/

/**
 * *@param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de la cantidad de dias
 */
int SumCantDias(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de las cantidades de dias al cuadrado
 */
int CantDiasCuad(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de los cuadrados de las cantidades de dias
 */
int SumCantDiasCuad(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de las ventas
 */
int SumVentas(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de la multiplicacion entre la cantidad de dias y las ventas
 */
int SumCantDias_xVentas(std::vector<Venta>);

/**
 * @param recibe SumCantDias
 * @param recibe CantDiasCuad
 * @param recibe SumCantDiasCuad
 * @param recibe SumVentas
 * @param recibe SumCantDias_xVentas
 * @return la pendiente de la ecuacion
 */
double Pendiente(double, double, double, double, double);

/**
 * @param recibe SumCantDias
 * @param recibe CantDiasCuad
 * @param recibe SumCantDiasCuad
 * @param recibe SumVentas
 * @param recibe SumCantDias_xVentas
 * @return la intercepcion de la ecuacion
 */
double intercepcion(double, double, double, double, double);

/**
 * @param recibe la pendiente
 * @param recibe la intercepcion
 * Realiza el llamado de la funcion para mostrar la ecuacion completa
 */
void MostrarMinimo(double, double);

/** Regresion lineal **/
/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return el promedio de la sumatoria total de la cantidades de dias
 */
double PromSumCantDias(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return el promedio de la sumatoria total de las ventas
 */
double PromSumVentas(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @param recibe el promedio de la cantidad de ventas
 * @return la sumatoria total de la ventas del dia por la cantidad de dias
 */
double SumCuadrado(std::vector<Venta>, double);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @param recibe el promedio de la cantidad de ventas
 * @param recibe el promedio de la cantidad de dias
 * @return la sumatoria total de los promedios
 */
double MultSumas(std::vector<Venta>, double, double);

/**
 * @param recibe el MultSumas
 * @param recibe el largo del vector
 * @return la covarianza
 */
double covarianza (double, int);

/**
 * @param recibe el promedio de la cantidad de dias
 * @param recibe el largo del vector
 * @return la desviacion estandar
 */
double Desviacion_Estandar(double, int);

/**
 * @param recibe la covarianza
 * @param recibe la Desviacion_Estandar
 * @return el resultado de b
 */
double calculob(double, double);

/**
 * @param recibe el promedio de cantidad de dias
 * @param recibe el promedio de las ventas
 * @param recibe b
 * @return el resultado de a
 */
double calculoa(double, double, double);

/**
 * @param recibe a
 * @param recibe b
 * Imprime la formula de regresion lineal
 */
void printformula(double, double);

/** Funcion Exponencial **/

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de la cantidad de dias por el logaritmo de la cantidad de ventas
 */
double SumCantLN(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de la cantidad de dias por la sumatoria del logaritmo de la cantidad de ventas
 */
double SumCantSumLN(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return la sumatoria total de la cantidad de ventas
 */
double PromCantVentasLn(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return el resultado de b
 */
double ExpB(std::vector<Venta>);

/**
 * @param Venta recibe un vector de tipo clase Venta
 * @return el resultado de a
 */
double ExpA(std::vector<Venta>);

/**
 * @param recibe a
 * @param recibe b
 * Imprime la funcion exponencial
 */
void printformula2(double, double);

/**
 * Imprime todas las funciones principales
 */
void funciones(std::vector<Venta>);

#endif // FUNCIONES_H_INCLUDED

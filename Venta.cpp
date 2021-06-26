#include "Venta.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

Venta::Venta(){
}

Venta::~Venta(){
}


void Venta::SetAno(int ano1){
    //2020-11-11 15:07:32.361
    ano=ano1;
}


void Venta::SetMes(int mes1){
    mes=mes1;
}

void Venta::SetDia(int dia1){
    dia=dia1;
}

void Venta::SetCantidad(int cant1){
    cant=cant1;
}

void Venta::SetMonto(int monto1){
    monto=monto1;
}

void Venta::SetTotal(int monto){
    total=monto;
}

void Venta::SetCantVentas(int a){
    cantventas=a;
}

int Venta::GetAno(){
    return ano;
}

int Venta::GetMes(){
    return mes;
}

int Venta::GetDia(){
    return dia;
}

int Venta::GetCantidad(){
    return cant;
}

int Venta::GetMonto(){
    return monto;
}

int Venta::GetTotal(){
    return total;
}

int Venta::GetCantVentas(){
    return cantventas;
}
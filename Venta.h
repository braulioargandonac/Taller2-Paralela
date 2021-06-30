#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <string>
#include <vector>

class Venta{
    private:
        int ano;
        int mes;
        int dia;
        int cant;
        int monto;
        double total;
        int cantventas;
    public:
        Venta();
        ~Venta();

        void SetAno(int );
        void SetMes(int );
        void SetDia(int );
        void SetCantidad(int );
        void SetMonto(int );
        void SetTotal(double );
        void SetCantVentas(int );

        int GetAno();
        int GetMes();
        int GetDia();
        int GetCantidad();
        int GetMonto();
        double GetTotal();
        int GetCantVentas();
};

#endif

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:27 AM
 */
#include <fstream>
using namespace std;
#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    void SetCantidad(double cantidad);
    double GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void operator =(Pedido&ped);
    
private:
    int codigo;
    double cantidad;
};

void operator<<(ofstream&,Pedido&);
void operator>>(ifstream&,Pedido&);
#endif /* PEDIDO_H */


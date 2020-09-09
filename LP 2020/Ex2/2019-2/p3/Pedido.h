/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: crimson
 *
 * Created on July 14, 2020, 1:16 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Pedido {
private:
    int pedido;
    double cantkg;
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetCantkg(double cantkg);
    double GetCantkg() const;
    void SetPedido(int pedido);
    int GetPedido() const;
    void operator=(const Pedido&);
};

ofstream& operator<<(ofstream&, Pedido&);
void operator>>(ifstream&, Pedido&);
#endif /* PEDIDO_H */


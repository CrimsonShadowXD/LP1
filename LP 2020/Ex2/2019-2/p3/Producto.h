/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: crimson
 *
 * Created on July 14, 2020, 1:11 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaPallets.h"
#include "Pedido.h"
#include "PlCola.h"
#include "Faltante.h"

using namespace std;

class Producto {
private:
    char *cod;
    class ListaPallets lpallet;
    PlCola <Pedido> cpedido;
    PlCola <Faltante> cfaltante;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCod(const char*  );
    void GetCod(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);

    void llenarP(ifstream&);
    void llenarPedidos(ifstream&);
    void imprimirPedidos(ofstream&);
    void atPedidos();
};

#endif /* PRODUCTO_H */


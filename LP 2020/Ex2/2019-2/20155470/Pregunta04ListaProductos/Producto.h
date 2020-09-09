/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:21 AM
 */
#include <fstream>

#include "ListaPallets.h"
#include "PlCola.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Faltante.h"

using namespace std;
#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    virtual ~Producto();
    void SetCodigo(char* cod);
    void GetCodigo(char* cod) const;
    
    void imprimirProducto(ofstream&);
    
private:
    char* codigo;
    ListaPallets listaPalletsProducto;
    PlCola<Pedido> colaPedidosProducto;
    PlCola<Faltante> colaFaltantes;
};

#endif /* PRODUCTO_H */


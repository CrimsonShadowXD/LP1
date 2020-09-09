/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoProducto.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:32 AM
 */
#include <fstream>

#include "Producto.h"
using namespace std;
#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

class NodoProducto {
public:
    NodoProducto();
    friend class ListaProductos;
private:
    Producto producto;
    NodoProducto *sig;
    
};

#endif /* NODOPRODUCTO_H */


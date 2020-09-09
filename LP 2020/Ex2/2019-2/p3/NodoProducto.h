/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoProducto.h
 * Author: crimson
 *
 * Created on July 14, 2020, 1:11 PM
 */

#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaProducto.h"
#include "Producto.h"

using namespace std;

class NodoProducto {
private:
    class Producto elem;
    class NodoProducto *sig;
public:
    NodoProducto();
    NodoProducto(const NodoProducto& orig);
    virtual ~NodoProducto();
    friend class ListaProducto;

};

#endif /* NODOPRODUCTO_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaProductos.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:33 AM
 */
#include <fstream>

#include "NodoProducto.h"
using namespace std;
#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H

class ListaProductos {
public:
    ListaProductos();
    virtual ~ListaProductos();
    
    void leerProductos(ifstream&);
    void insertarProducto(char*);
    void imprimirProductos(ofstream&);
    
private:
    NodoProducto *listaProductos;
};

#endif /* LISTAPRODUCTOS_H */


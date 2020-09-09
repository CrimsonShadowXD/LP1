/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaProducto.h
 * Author: crimson
 *
 * Created on July 14, 2020, 1:11 PM
 */

#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoProducto.h"

using namespace std;

class ListaProducto {
private:
    class NodoProducto *inicio;
public:
    ListaProducto();
    ListaProducto(const ListaProducto& orig);
    virtual ~ListaProducto();
    
    void crear(ifstream&);
    void insertar(NodoProducto*);
    void imprime(ofstream&);
    void impPcod(ofstream&);
    void llenarPallet(ifstream&);
    void impLP(ofstream&);
    void leerPedidos(ifstream&);
    void impCPed(ofstream&);
    void atenderPedidos();
};

#endif /* LISTAPRODUCTO_H */


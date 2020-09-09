/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaVehiculos.h
 * Author: crimson
 *
 * Created on July 4, 2020, 4:59 PM
 */

#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoV.h"
using namespace std;

class ListaVehiculos {
private:
    class NodoV *Inicio;
    class NodoV *Fin;
public:
    ListaVehiculos();
    ListaVehiculos(const ListaVehiculos& orig);
    virtual ~ListaVehiculos();

    void insertar(NodoV *nuevo);
    void crear(ifstream&);
    void imprimir(ofstream&);
    
    void cargarinfr(char*,int);
};

#endif /* LISTAVEHICULOS_H */


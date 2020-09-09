/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaVehiculos.h
 * Author: crimson
 *
 * Created on July 20, 2020, 6:37 AM
 */

#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoVehiculo.h"
using namespace std;

class listaVehiculos {
private:
    class NodoVehiculo *inicio,*ultimo;
public:
    listaVehiculos();
    listaVehiculos(const listaVehiculos& orig);
    virtual ~listaVehiculos();

    void cargar(ifstream&);
    void insertar(NodoVehiculo*);
    void imprimir(ofstream&);
    
    void imprimirRev(ofstream&);
    void imprimirOrden(ofstream&,int);
    
    int* devolverTodasLasfaltas();
};

#endif /* LISTAVEHICULOS_H */


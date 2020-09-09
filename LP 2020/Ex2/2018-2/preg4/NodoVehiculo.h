/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoVehiculo.h
 * Author: crimson
 *
 * Created on July 20, 2020, 6:37 AM
 */

#ifndef NODOVEHICULO_H
#define NODOVEHICULO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Vehiculos.h"
#include "listaVehiculos.h"
using namespace std;

class NodoVehiculo {
private:
    class Vehiculos elem;
    class NodoVehiculo *sig,*ant;
public:
    NodoVehiculo();
    NodoVehiculo(const NodoVehiculo& orig);
    virtual ~NodoVehiculo();
    friend class listaVehiculos;
};

#endif /* NODOVEHICULO_H */


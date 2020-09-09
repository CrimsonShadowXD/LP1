/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoV.h
 * Author: crimson
 *
 * Created on July 4, 2020, 5:00 PM
 */

#ifndef NODOV_H
#define NODOV_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Vehiculo.h"
#include "ListaVehiculos.h"

using namespace std;

class NodoV {
private:
    Vehiculo elem;
    NodoV *sig;
    NodoV *ant;
public:
    NodoV();
    NodoV(const NodoV& orig);
    virtual ~NodoV();
    friend class ListaVehiculos;
};

#endif /* NODOV_H */


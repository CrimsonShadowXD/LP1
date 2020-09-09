/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoV.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#ifndef NODOV_H
#define NODOV_H
#include "Vehiculo.h"

class NodoV {
public:
    NodoV();
private:
    Vehiculo elem;
    NodoV *ant;
    NodoV *sig;
    friend class ListaVehiculos;    
};

#endif /* NODOV_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoCola.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:40 AM
 */

#ifndef PLNODOCOLA_H
#define PLNODOCOLA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlCola.h"

using namespace std;
template <typename T>class PlCola;

template <typename T>
class PlNodoCola {
private:
    T dato;
    class PlNodoCola<T> *sig;
public:
    PlNodoCola();
    friend class PlCola<T>;
};

template <typename T>
PlNodoCola<T>::PlNodoCola() {
    sig = NULL;
}



#endif /* PLNODOCOLA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoCola.h
 * Author: crimson
 *
 * Created on July 15, 2020, 5:20 PM
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


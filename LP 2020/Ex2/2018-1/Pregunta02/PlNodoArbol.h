/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoArbol.h
 * Author: crimson
 *
 * Created on July 18, 2020, 4:42 PM
 */

#ifndef PLNODOARBOL_H
#define PLNODOARBOL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlArbol.h"

using namespace std;
template <typename T>class PlArbol;

template <typename T>
class PlNodoArbol {
private:
    T dato;
    class PlNodoArbol<T> *izq;
    class PlNodoArbol<T> *der;
public:
    PlNodoArbol();
    friend class PlArbol<T>;
};

template <typename T>
PlNodoArbol<T>::PlNodoArbol() {
    izq = NULL;
    der = NULL;
}


#endif /* PLNODOARBOL_H */


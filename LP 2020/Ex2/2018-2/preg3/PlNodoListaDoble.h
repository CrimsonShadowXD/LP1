/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoListaDoble.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:07 AM
 */

#ifndef PLNODOLISTADOBLE_H
#define PLNODOLISTADOBLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlListaDoble.h"

using namespace std;
template <typename T>class PlListaDoble;

template <typename T>
class PlNodoListaDoble {
private:
    T dato;
    class PlNodoListaDoble<T> *sig,*ant;
public:
    PlNodoListaDoble();
    friend class PlListaDoble<T>;
};

template <typename T>
PlNodoListaDoble<T>::PlNodoListaDoble() {
    sig = NULL;
    ant = NULL;
}


#endif /* PLNODOLISTADOBLE_H */


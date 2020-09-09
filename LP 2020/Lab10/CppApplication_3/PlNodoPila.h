/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoPila.h
 * Author: crimson
 *
 * Created on July 15, 2020, 8:31 PM
 */

#ifndef PLNODOPILA_H
#define PLNODOPILA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlPila.h"

using namespace std;
template <typename T>class PlPila;

template <typename T>
class PlNodoPila {
private:
    T dato;
    class PlNodoPila<T> *sig;
public:
    PlNodoPila();
    friend class PlPila<T>;
};

template <typename T>
PlNodoPila<T>::PlNodoPila() {
    sig = NULL;
}


#endif /* PLNODOPILA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoLista.h
 * Author: crimson
 *
 * Created on July 15, 2020, 6:48 PM
 */

#ifndef PLNODOLISTA_H
#define PLNODOLISTA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlLista.h"

using namespace std;
template <typename T>class PlLista;

template <typename T>
class PlNodoLista {
private:
    T dato;
    class PlNodoLista<T> *sig;
public:
    PlNodoLista();
    friend class PlLista<T>;
};

template <typename T>
PlNodoLista<T>::PlNodoLista() {
    sig = NULL;
}

#endif /* PLNODOLISTA_H */


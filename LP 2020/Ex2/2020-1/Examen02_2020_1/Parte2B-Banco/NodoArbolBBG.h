/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoArbolBBG.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:17 AM
 */

#ifndef NODOARBOLBBG_H
#define NODOARBOLBBG_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "ArbolBBG.h"

using namespace std;
template <typename T>class ArbolBBG;

template <typename T>
class NodoArbolBBG {
private:
    T dato;
    class NodoArbolBBG<T> *izq;
    class NodoArbolBBG<T> *der;
public:
    NodoArbolBBG();
    friend class ArbolBBG<T>;
};

template <typename T>
NodoArbolBBG<T>::NodoArbolBBG() {
    izq = NULL;
    der = NULL;
}



#endif /* NODOARBOLBBG_H */


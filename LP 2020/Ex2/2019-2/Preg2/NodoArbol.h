/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoArbol.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:37 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "ArbolPallet.h"
using namespace std;

class NodoArbol {
private:
    class Pallet *elem;
    class NodoArbol *der,*izq;
public:
    NodoArbol();
    NodoArbol(const NodoArbol& orig);
    virtual ~NodoArbol();
    friend class ArbolPallet;
};

#endif /* NODOARBOL_H */


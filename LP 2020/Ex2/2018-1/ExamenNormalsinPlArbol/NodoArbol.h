/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoArbol.h
 * Author: crimson
 *
 * Created on July 19, 2020, 1:09 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Libro.h"
#include "Arbol.h"
using namespace std;

class NodoArbol {
private:
    class Libro elem;
    class NodoArbol *izq;
    class NodoArbol *der;
public:
    NodoArbol();
    NodoArbol(const NodoArbol& orig);
    virtual ~NodoArbol();
    friend class Arbol;
};

#endif /* NODOARBOL_H */


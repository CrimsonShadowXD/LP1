/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: crimson
 *
 * Created on July 13, 2020, 1:21 AM
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ArbolBB.h"
#include "Autor.h"

using namespace std;

class Nodo {
private:
    class Autor elem;
    class Nodo *der;
    class Nodo *izq;
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();

};

#endif /* NODO_H */


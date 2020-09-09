/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoC.h
 * Author: crimson
 *
 * Created on July 4, 2020, 4:59 PM
 */

#ifndef NODOC_H
#define NODOC_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Conductor.h"
#include "ListaConductores.h"

using namespace std;

class NodoC {
private:
    Conductor elem;
    NodoC *sig;
    NodoC *ant;
public:
    NodoC();
    NodoC(const NodoC& orig);
    virtual ~NodoC();
    friend class ListaConductores;
};

#endif /* NODOC_H */


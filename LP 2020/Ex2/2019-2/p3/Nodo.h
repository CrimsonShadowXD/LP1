/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: crimson
 *
 * Created on July 9, 2020, 1:18 AM
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "ListaPallets.h"

using namespace std;

class Nodo {
private:
    class Pallet elem;
    class Nodo *sig;
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class ListaPallets;
};

#endif /* NODO_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoP.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:48 PM
 */

#ifndef NODOP_H
#define NODOP_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaPallet.h"
#include "Pallet.h"
using namespace std;

class NodoP {
private:
    class Pallet *elem;
    class NodoP *sig,*ant;
public:
    NodoP();
    NodoP(const NodoP& orig);
    virtual ~NodoP();

    friend class ListaPallet;
};

#endif /* NODOP_H */

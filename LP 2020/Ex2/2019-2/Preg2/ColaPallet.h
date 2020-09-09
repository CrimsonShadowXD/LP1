/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaPallet.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:21 PM
 */

#ifndef COLAPALLET_H
#define COLAPALLET_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "PalletEU.h"
#include "PalletPE.h"
#include "PalletUS.h"
#include "NodoCola.h"
using namespace std;

class ColaPallet {
private:
    class NodoCola *inicio,*fin;
public:
    ColaPallet();
    ColaPallet(const ColaPallet& orig);
    virtual ~ColaPallet();

    void crear(ifstream&);
    void insertar(Pallet*);
    void imprimir(ofstream&);
    Pallet* Pop();
    bool vacia();
};

#endif /* COLAPALLET_H */

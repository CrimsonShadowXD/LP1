/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaPallet.h
 * Author: crimson
 *
 * Created on July 20, 2020, 6:23 PM
 */

#ifndef PILAPALLET_H
#define PILAPALLET_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "PalletEU.h"
#include "PalletPE.h"
#include "PalletUS.h"
#include "NodoPila.h"
using namespace std;

class PilaPallet {
private:
    class NodoPila *top;
public:
    PilaPallet(); 
    virtual ~PilaPallet();

    void crear(ifstream&);
    void insertar(Pallet*);
    void imprimir(ofstream&);
    Pallet* Desapilar();
    bool vacia();
};

#endif /* PILAPALLET_H */




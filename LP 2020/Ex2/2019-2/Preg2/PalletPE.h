/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletPE.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:36 PM
 */

#ifndef PALLETPE_H
#define PALLETPE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
using namespace std;

class PalletPE : public Pallet {
private:

public:
    PalletPE();
    PalletPE(const PalletPE& orig);
    virtual ~PalletPE();

    void leer(ifstream&);
    void imprimir(ofstream&);
    int getPeso();
    char getTipo();
};

#endif /* PALLETPE_H */


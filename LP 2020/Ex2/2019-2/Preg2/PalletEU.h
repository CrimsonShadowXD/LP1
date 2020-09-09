/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletEU.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:36 PM
 */

#ifndef PALLETEU_H
#define PALLETEU_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
using namespace std;

class PalletEU : public Pallet {
private:

public:
    PalletEU();
    PalletEU(const PalletEU& orig);
    virtual ~PalletEU();

    void leer(ifstream&);
    void imprimir(ofstream&);
    int getPeso();
    char getTipo();
};

#endif /* PALLETEU_H */


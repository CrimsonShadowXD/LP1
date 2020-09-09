/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletEU.h
 * Author: crimson
 *
 * Created on July 8, 2020, 11:08 PM
 */

#ifndef PALLETEU_H
#define PALLETEU_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "PalletBase.h"

using namespace std;

class PalletEU:public PalletBase {
private:
    int cap;
public:
    PalletEU();
    PalletEU(const PalletEU& orig);
    virtual ~PalletEU();
    void setCap(int cap);
    int getCap() const;

//    void imprimir(ofstream &out);
    void leer(ifstream &in);
    void getTipo(char*);
    int getPeso();
};

#endif /* PALLETEU_H */


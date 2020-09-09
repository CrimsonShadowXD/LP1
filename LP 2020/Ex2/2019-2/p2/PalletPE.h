/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletPE.h
 * Author: crimson
 *
 * Created on July 8, 2020, 11:09 PM
 */

#ifndef PALLETPE_H
#define PALLETPE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "PalletBase.h"

using namespace std;

class PalletPE :public PalletBase{
private:
    int cap;
public:
    PalletPE();
    PalletPE(const PalletPE& orig);
    virtual ~PalletPE();
    void SetCap(int cap);
    int GetCap() const;

//    void imprimir(ofstream &out);
    void leer(ifstream &in);
    void getTipo(char*);
    int getPeso();
};

#endif /* PALLETPE_H */


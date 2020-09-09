/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletUS.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:35 PM
 */

#ifndef PALLETUS_H
#define PALLETUS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
using namespace std;

class PalletUS : public Pallet {
private:
    
public:
    PalletUS();
    PalletUS(const PalletUS& orig);
    virtual ~PalletUS();
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    int getPeso();
    char getTipo();
};

#endif /* PALLETUS_H */


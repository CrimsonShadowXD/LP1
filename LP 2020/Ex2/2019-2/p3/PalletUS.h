/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletUS.h
 * Author: crimson
 *
 * Created on July 8, 2020, 11:08 PM
 */

#ifndef PALLETUS_H
#define PALLETUS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "PalletBase.h"

using namespace std;

class PalletUS:public PalletBase {
private:
    int cap;
public:
    PalletUS();
    PalletUS(const PalletUS& orig);
    virtual ~PalletUS();
    void SetCap(int cap);
    int GetCap() const;

//    void imprimir(ofstream &out);
    void leer(ifstream &in);
    void getTipo(char*);
    int getPeso();
};

#endif /* PALLETUS_H */


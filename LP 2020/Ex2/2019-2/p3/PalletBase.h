/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletBase.h
 * Author: crimson
 *
 * Created on July 8, 2020, 11:08 PM
 */

#ifndef PALLETBASE_H
#define PALLETBASE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class PalletBase {
private:
    char *id;
public:
    PalletBase();
    PalletBase(const PalletBase& orig);
    virtual ~PalletBase();
    void SetId(const char*);
    void GetId(char*) const;
    
//    virtual void imprimir(ofstream &out) = 0;
    virtual void leer(ifstream &in)=0;
    virtual void getTipo(char*)=0;
    virtual int getPeso()=0;
};

#endif /* PALLETBASE_H */


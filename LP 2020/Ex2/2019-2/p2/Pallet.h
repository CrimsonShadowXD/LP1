/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pallet.h
 * Author: crimson
 *
 * Created on July 9, 2020, 1:22 AM
 */

#ifndef PALLET_H
#define PALLET_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "PalletBase.h"
#include "PalletEU.h"
#include "PalletUS.h"
#include "PalletPE.h"

using namespace std;

class Pallet {
private:
    class PalletBase *elem;
public:
    Pallet();
    Pallet(const Pallet& orig);
    virtual ~Pallet();

    void leerP(ifstream&);
    void imprimirP(ofstream&);
};

#endif /* PALLET_H */


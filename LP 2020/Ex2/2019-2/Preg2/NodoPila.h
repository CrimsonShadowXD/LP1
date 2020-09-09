/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPila.h
 * Author: crimson
 *
 * Created on July 20, 2020, 6:24 PM
 */

#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "PilaPallet.h"
using namespace std;

class NodoPila {
private:
    class Pallet *elem;
    class NodoPila *sig;
public:
    NodoPila();
    NodoPila(const NodoPila& orig);
    virtual ~NodoPila();
    friend class PilaPallet;
};

#endif /* NODOPILA_H */

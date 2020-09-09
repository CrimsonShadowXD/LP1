/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:22 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "ColaPallet.h"
using namespace std;

class NodoCola {
private:
    class Pallet *elem;
    class NodoCola *sig;
public:
    NodoCola();
    NodoCola(const NodoCola& orig);
    virtual ~NodoCola();
    friend class ColaPallet;
};

#endif /* NODOCOLA_H */


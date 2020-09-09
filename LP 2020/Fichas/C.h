/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C.h
 * Author: crimson
 *
 * Created on July 4, 2020, 7:38 PM
 */

#ifndef C_H
#define C_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Ficha.h"

using namespace std;

class C:public Ficha {
private:

public:
    C();
    C(const C& orig);
    virtual ~C();
    void imprimir(ofstream&);
    void mover(char,int);
};

#endif /* C_H */


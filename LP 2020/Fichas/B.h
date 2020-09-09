/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   B.h
 * Author: crimson
 *
 * Created on July 4, 2020, 7:38 PM
 */

#ifndef B_H
#define B_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Ficha.h"

using namespace std;

class B:public Ficha {
private:

public:
    B();
    B(const B& orig);
    virtual ~B();
    
    void imprimir(ofstream&);
    void mover(char,int);
};

#endif /* B_H */


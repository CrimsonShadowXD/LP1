/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A.h
 * Author: crimson
 *
 * Created on July 4, 2020, 7:37 PM
 */

#ifndef A_H
#define A_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Ficha.h"

using namespace std;

class A:public Ficha {
private:

public:
    A();
    A(const A& orig);
    virtual ~A();

    void imprimir(ofstream&);
    void mover(char,int);
};

#endif /* A_H */


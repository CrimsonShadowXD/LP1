/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Superclase.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:07 AM
 */

#ifndef SUPERCLASE_H
#define SUPERCLASE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Paper.h"
#include "JournalPaper.h"
#include "ConferencePaper.h"

using namespace std;

class Superclase {
private:
    Paper *lstPapers[100]; 
public:
    Superclase();
    Superclase(const Superclase& orig);
    virtual ~Superclase();
    void leer(int&);
    void citar(int);
};

#endif /* SUPERCLASE_H */


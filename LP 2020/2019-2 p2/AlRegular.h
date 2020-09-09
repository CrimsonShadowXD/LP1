/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlRegular.h
 * Author: crimson
 *
 * Created on July 7, 2020, 5:28 AM
 */

#ifndef ALREGULAR_H
#define ALREGULAR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "BaseAlum.h"

using namespace std;

class AlRegular:public BaseAlum {
private:
    char *espec;
    char *facul;
public:
    AlRegular();
    AlRegular(const AlRegular& orig);
    virtual ~AlRegular();
    void SetFacul(char* );
    void GetFacul(char*) const;
    void SetEspec(char* );
    void GetEspec(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
};

#endif /* ALREGULAR_H */


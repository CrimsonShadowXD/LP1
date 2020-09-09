/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseAlum.h
 * Author: crimson
 *
 * Created on July 7, 2020, 5:28 AM
 */

#ifndef BASEALUM_H
#define BASEALUM_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class BaseAlum {
private:
    int codigo;
    char* nombre;
public:
    BaseAlum();
    BaseAlum(const BaseAlum& orig);
    virtual ~BaseAlum();
    void SetNombre(char*);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;

    virtual void imprimir(ofstream &out) = 0;
    virtual void leer(ifstream &in)=0;
};

#endif /* BASEALUM_H */


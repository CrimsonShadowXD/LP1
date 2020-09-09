/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ficha.h
 * Author: crimson
 *
 * Created on July 4, 2020, 7:24 PM
 */

#ifndef FICHA_H
#define FICHA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Ficha {
private:
    char *id;
    int fil;
    int col;
public:
    Ficha();
    Ficha(const Ficha& orig);
    virtual ~Ficha();
    void SetCol(int col);
    int GetCol() const;
    void SetFil(int fil);
    int GetFil() const;
    void SetId(char* );
    void GetId(char*) const;
    void asigna(char*,int,int);
    virtual void imprimir(ofstream&)=0;
    virtual void mover(char,int)=0;
};

#endif /* FICHA_H */


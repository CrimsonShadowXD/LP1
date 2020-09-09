/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pallet.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:35 PM
 */

#ifndef PALLET_H
#define PALLET_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Pallet {
private:
    char *id;
public:
    Pallet();
    Pallet(const Pallet& orig);
    virtual ~Pallet();
    void SetId(const char*  );
    void GetId(char*) const;
    
    virtual void leer(ifstream&)=0;
    virtual void imprimir(ofstream&)=0;
    virtual int getPeso()=0;
    virtual char getTipo()=0;

};

#endif /* PALLET_H */


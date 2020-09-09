/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faltante.h
 * Author: crimson
 *
 * Created on July 14, 2020, 1:23 PM
 */

#ifndef FALTANTE_H
#define FALTANTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Faltante {
private:
    int codp;
    double cantp;
public:
    Faltante();
    Faltante(const Faltante& orig);
    virtual ~Faltante();
    void SetCantp(double cantp);
    double GetCantp() const;
    void SetCodp(int codp);
    int GetCodp() const;
    
    void operator=(const Faltante&cli);
};
ofstream& operator<<(ofstream&, Faltante&);
void operator>>(ifstream&, Faltante&);

#endif /* FALTANTE_H */


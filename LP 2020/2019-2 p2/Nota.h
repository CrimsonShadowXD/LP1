/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: crimson
 *
 * Created on July 7, 2020, 4:32 AM
 */

#ifndef NOTA_H
#define NOTA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Nota {
private:
    char *codcur;
    int nota;
    char *sem;
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();   

    void setSem(char*  );
    void getSem(char*) const;
    void setNota(int nota);
    int getNota() const;
    void setCodcur(char*  );
    void getCodcur(char*) const;
    
    void leerNota(ifstream&);
    void imprimirNota(ofstream&);
};

#endif /* NOTA_H */


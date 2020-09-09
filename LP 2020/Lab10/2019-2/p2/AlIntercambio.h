/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlIntercambio.h
 * Author: crimson
 *
 * Created on July 7, 2020, 5:29 AM
 */

#ifndef ALINTERCAMBIO_H
#define ALINTERCAMBIO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "BaseAlum.h"

using namespace std;

class AlIntercambio:public BaseAlum {
private:
    char *porigen;
    char **idiomas;
    int semestres;
public:
    AlIntercambio();
    AlIntercambio(const AlIntercambio& orig);
    virtual ~AlIntercambio();
    void SetSemestres(int semestres);
    int GetSemestres() const;
    void SetPorigen(char*);
    void GetPorigen(char*) const;
    void SetIdiomas(char** idiomas);
    char** GetIdiomas() const;
    
    char getTipo();
    void leer(ifstream&);
    void imprimir(ofstream&);


};

#endif /* ALINTERCAMBIO_H */


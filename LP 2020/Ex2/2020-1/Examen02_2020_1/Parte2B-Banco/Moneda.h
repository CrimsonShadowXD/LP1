/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moneda.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:43 AM
 */

#ifndef MONEDA_H
#define MONEDA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Moneda {
private:
    char simbolo;
    double equivalencia;
    char *nombre;
public:
    Moneda();
    Moneda(const Moneda& orig);
    virtual ~Moneda();
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetEquivalencia(double equivalencia);
    double GetEquivalencia() const;
    void SetSimbolo(char simbolo);
    char GetSimbolo() const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    
    void operator=(const Moneda&);
    bool operator==(const Moneda&);
    bool operator>(const Moneda&);
    bool operator<(const Moneda&);
};
ofstream& operator<<(ofstream&, Moneda&);
void operator>>(ifstream&, Moneda&);

#endif /* MONEDA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculos.h
 * Author: crimson
 *
 * Created on July 20, 2020, 6:23 AM
 */

#ifndef VEHICULOS_H
#define VEHICULOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>
#include <iterator>

using namespace std;

class Vehiculos {
private:
    char *placa;
    list <int> infracciones;
public:
    Vehiculos();
    Vehiculos(const Vehiculos& orig);
    virtual ~Vehiculos();
    void SetPlaca(const char*  );
    void GetPlaca(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);

};

#endif /* VEHICULOS_H */


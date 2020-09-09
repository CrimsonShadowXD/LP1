/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: crimson
 *
 * Created on July 4, 2020, 4:58 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>

using namespace std;

class Vehiculo {
private:
    char *placa;
    list <int> infracciones;
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    
    void SetPlaca(char*);
    void GetPlaca(char*) const;
    
    void leer(ifstream&in);
    void imprimir(ofstream&out);
    bool operator >(Vehiculo v);
    
    void anadir(int);

};

#endif /* VEHICULO_H */


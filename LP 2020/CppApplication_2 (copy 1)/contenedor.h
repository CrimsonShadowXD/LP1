/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   contenedor.h
 * Author: crimson
 *
 * Created on July 3, 2020, 2:18 AM
 */

#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Intercambio.h"
#include "Nacional.h"
#include "sobrecarga.h"

using namespace std;

class contenedor {
private:
    Intercambio *ArrInt;
    Nacional *ArrNac;
public:
    contenedor();
    contenedor(const contenedor& orig);
    virtual ~contenedor();
    void incrementarInt(int&,int&);
    void incrementarNac(int&,int&);
    void lee(int&,int&,int&,int&);
    void imprimeNac(int);
    void imprimeInt(int);
};


#endif /* CONTENEDOR_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 7, 2020, 5:19 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "BaseAlum.h"
#include "AlIntercambio.h"
#include "AlRegular.h"

using namespace std;

class Alumno {
private:
    class BaseAlum *elem;
    
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    
    void leerAl(ifstream&);
    void imprimirAl(ofstream&);
};

#endif /* ALUMNO_H */


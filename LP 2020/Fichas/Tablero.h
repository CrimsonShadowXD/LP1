/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: crimson
 *
 * Created on July 4, 2020, 9:04 PM
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Ficha.h"
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

class Tablero {
private:
    Ficha *ficha[100];
    int numfichas;
public:
    Tablero();
    Tablero(const Tablero& orig);
    virtual ~Tablero();

    void leerFichas(ifstream&);
    void colocarFichas(char*,char,int,int);
    void leerMovimientos(ifstream&);
    void moverFicha(char*,char,int);
    void imprimeDatos(ofstream&);
};

#endif /* TABLERO_H */


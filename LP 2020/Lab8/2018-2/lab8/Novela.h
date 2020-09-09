/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.h
 * Author: crimson
 *
 * Created on July 8, 2020, 3:59 AM
 */

#ifndef NOVELA_H
#define NOVELA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Libro.h"

using namespace std;

class Novela:public Libro {
private:
    double arr[300];
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();

    void operator=(const Novela&);
};

ifstream &operator >> (ifstream &,Novela &);
ofstream &operator << (ofstream &, const Novela &);

#endif /* NOVELA_H */


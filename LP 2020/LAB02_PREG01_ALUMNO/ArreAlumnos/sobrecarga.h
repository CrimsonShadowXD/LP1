/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: cueva
 *
 * Created on 2 de julio de 2020, 10:17 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include <fstream>
#include "Nacional.h"
#include "Intercambio.h"
using namespace std;

ofstream &operator << (ofstream &, const Nacional &);
ofstream &operator << (ofstream &, const Intercambio &);

ifstream &operator >> (ifstream &,Intercambio &);
ifstream &operator >> (ifstream &,Nacional &);


#endif /* SOBRECARGA_H */

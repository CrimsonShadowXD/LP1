/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: cueva
 *
 * Created on 25 de junio de 2020, 11:41 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream &operator >> (ifstream &, Conductor &);
ifstream &operator >> (ifstream &, Faltas &);
ofstream &operator << (ofstream &, Conductor &);

#endif /* SOBRECARGA_H */

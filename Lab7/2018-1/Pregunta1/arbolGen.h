/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbolGen.h
 * Author: La Rosa
 *
 * Created on 27 de octubre de 2019, 13:22
 */

#ifndef ARBOLGEN_H
#define ARBOLGEN_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void *crearNodo(void *reg);

int comparar(void *dato,void *reg);

void insertar(void *nodoActual,void *reg);

#endif /* ARBOLGEN_H */


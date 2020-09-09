/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sobrecarga.h
 * Author: cueva
 *
 * Created on 8 de julio de 2020, 01:31 PM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include "Persona.h"

    ofstream &operator << (ofstream &, Persona *&);
    ifstream &operator >> (ifstream &, Persona *&);

#endif /* SOBRECARGA_H */

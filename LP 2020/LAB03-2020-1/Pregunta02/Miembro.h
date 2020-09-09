/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:07 AM
 */

#ifndef MIEMBRO_H
#define MIEMBRO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Alumno.h"
#include "Profesor.h"

using namespace std;

class Miembro {
private:
    Alumno *lalumno;
    Profesor *lprofesor;
public:
    Miembro();
    Miembro(const Miembro& orig);
    virtual ~Miembro();
    void operator +(const Alumno &);
    void operator +(const Profesor &);
};

#endif /* MIEMBRO_H */


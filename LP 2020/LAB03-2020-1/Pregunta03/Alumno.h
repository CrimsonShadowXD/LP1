/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:06 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Persona.h"

using namespace std;

class Alumno:public Persona {
private:
    int escala;
    char *especialidad;
    char *facultad;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetFacultad(char*);
    void GetFacultad(char*) const;
    void SetEspecialidad(char*);
    void GetEspecialidad(char*) const;
    void SetEscala(int escala);
    int GetEscala() const;
};

#endif /* ALUMNO_H */


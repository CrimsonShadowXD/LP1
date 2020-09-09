/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:06 AM
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Persona.h"

using namespace std;

class Profesor:public Persona {
private:
    char *categoria;
    char *dedicacion;
    char *seccion;
    char *grado;
public:
    Profesor();
    Profesor(const Profesor& orig);
    virtual ~Profesor();
    void SetGrado(char*);
    void GetGrado(char*) const;
    void SetSeccion(char*);
    void GetSeccion(char*) const;
    void SetDedicacion(char*);
    void GetDedicacion(char*) const;
    void SetCategoria(char*);
    void GetCategoria(char*) const;
};

#endif /* PROFESOR_H */


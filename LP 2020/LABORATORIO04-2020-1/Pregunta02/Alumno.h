/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:03 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Persona.h"

using namespace std;

class Alumno : public Persona {
private:
    int escala;
    char *especialidad;
    char *facultad;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetFacultad(const char*  );
    void GetFacultad(char*) const;
    void SetEspecialidad(const char*  );
    void GetEspecialidad(char*) const;
    void SetEscala(int escala);
    int GetEscala() const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    int getPrio();
};

#endif /* ALUMNO_H */


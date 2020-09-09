/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:05 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Persona.h"
using namespace std;

class Alumno: public Persona {
private:
    int escala;
    char *especialidad,*facultad;
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
    void operator=(const Alumno&);
    bool operator==(const Alumno&);
    bool operator>(const Alumno&);
    bool operator<(const Alumno&);
};
ofstream& operator<<(ofstream&, Alumno&);
void operator>>(ifstream&, Alumno&);
#endif /* ALUMNO_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:02 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Curso.h"
#include "Acurso.h"

using namespace std;

class Alumno {
private:
    int codigo;
    char tipo;
    char *nombre;
    class Curso lcurso[100];
    int numcur;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char* nombre);
    void GetNombre(char *nombre) const;
    void SetNumcur(int numcur);
    int GetNumcur() const;
    
    
    void operator + (const Acurso&);
    void operator *(const Acurso&);
    void operator -(const Acurso&);
    float operator /(int);
    float operator --(int);
    float operator ++(int);
};

#endif /* ALUMNO_H */


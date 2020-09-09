/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumnos.h
 * Author: crimson
 *
 * Created on July 2, 2020, 7:33 PM
 */

#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Curso.h"
#include "ACurso.h"

using namespace std;

class Alumnos {
private:
    int codigo;
    char tipo;
    char *nombre;
    Curso lcurso[100];
    int numcur;
public:
    Alumnos();
    virtual ~Alumnos();
    void SetNumcur(int numcur);
    int GetNumcur() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void operator +(const ACurso &);
    void operator *(const ACurso &);
    void operator -(const ACurso &);
    float operator /(int);
    float operator --(int);
    float operator ++(int);
};

#endif /* ALUMNOS_H */


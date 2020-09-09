/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 15, 2020, 9:24 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>
#include <iterator>
#include "Curso.h"

using namespace std;

class Alumno {
private:
    char *nom;
    int cod;
    char tipo;
    list <Curso> lcurso;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCod(int cod);
    int GetCod() const;
    void SetNom(const char*);
    void GetNom(char*) const;
    void CargarNotas();
    void ImprimirCursos(ofstream&);
    bool vacioCurso();
    
    void operator=(const Alumno&);
};

ofstream& operator<<(ofstream&, Alumno&);
void operator>>(ifstream&, Alumno&);

#endif /* ALUMNO_H */


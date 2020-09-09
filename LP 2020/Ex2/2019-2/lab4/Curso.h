/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: crimson
 *
 * Created on July 15, 2020, 9:34 AM
 */

#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Curso {
private:
    char *ccurso;
    int nota,ciclo;
    double credito;
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    void SetCredito(double credito);
    double GetCredito() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCcurso(const char*);
    void GetCcurso(char*) const;
    
    void operator=(const Curso&);
};

ofstream& operator<<(ofstream&, Curso&);
void operator>>(ifstream&, Curso&);

#endif /* CURSO_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: crimson
 *
 * Created on July 2, 2020, 7:34 PM
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
    int ciclo;
    int nota;
    float credito;
public:
    Curso();
    virtual ~Curso();
    void SetCredito(float credito);
    float GetCredito() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCcurso(char* ccurso);
    void GetCcurso(char*) const;
    
    Curso operator =(const Curso &);
    void asignar(const Curso &);
    bool operator ==(const Curso &);
    bool compare(const Curso &);
};

#endif /* CURSO_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:02 AM
 */

#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

class Curso {
private: 
    char *ccurso;
    int ciclo;
    int nota;
    float credito;
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    void SetCodigo(char* ccurso);
    void GetCodigo(char *ccurso) const;
    void SetCredito(float credito);
    float GetCredito() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    
    void asignar(const Curso&);
    bool compare(const Curso&);
    Curso operator = (const Curso&);
    bool operator ==(const Curso&);
};

#endif /* CURSO_H */


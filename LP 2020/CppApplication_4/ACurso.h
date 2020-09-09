/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ACurso.h
 * Author: crimson
 *
 * Created on July 2, 2020, 7:33 PM
 */

#ifndef ACURSO_H
#define ACURSO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Curso.h"

using namespace std;

class ACurso {
private:
    int codigo;
    Curso clcurso;
    char operacion;
public:
    ACurso();
    virtual ~ACurso();
    void SetOperacion(char operacion);
    char GetOperacion() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void AsignarDatosCurso(char*,int,int,float);
    void ObtenerCurso(char*) const;
    int ObtenerCiclo() const;
    int ObtenerNota() const;
    float ObtenerCredito() const;

};

#endif /* ACURSO_H */


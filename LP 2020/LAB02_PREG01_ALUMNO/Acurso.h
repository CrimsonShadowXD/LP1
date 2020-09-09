/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acurso.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:04 AM
 */

#ifndef ACURSO_H
#define ACURSO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Curso.h"

using namespace std;

class Acurso {
private:
    int codigo;
    class Curso clcurso;
    char operacion;
public:
    Acurso();
    Acurso(const Acurso& orig);
    virtual ~Acurso();
    void SetOperacion(char operacion);
    char GetOperacion() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetClcurso(const Curso &clcurso);  // lo mas adecuado es pasarlo por referencia 
    Curso GetClcurso() const;
};

#endif /* ACURSO_H */


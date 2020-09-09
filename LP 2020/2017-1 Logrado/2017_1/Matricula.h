/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matricula.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 10:36 PM
 */

#include <fstream>
#include "ListaAlumnos.h"
#include "ListaCursos.h"

using namespace std;

#ifndef MATRICULA_H
#define MATRICULA_H

class Matricula {
public:
    Matricula();
    virtual ~Matricula();
    
    void leer();
    void imprimir();
    
    void matricular();
    
    void procesar();
    
private:
    ListaAlumnos alumnos;
    ListaCursos cursos;

};

#endif /* MATRICULA_H */


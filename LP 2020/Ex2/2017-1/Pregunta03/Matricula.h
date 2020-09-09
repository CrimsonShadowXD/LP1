/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matricula.h
 * Author: crimson
 *
 * Created on July 19, 2020, 5:19 PM
 */

#ifndef MATRICULA_H
#define MATRICULA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>
#include "Lista.h"
#include "Curso.h"

using namespace std;

class Matricula {
private:
    class Lista alumnos;
    list <Curso> cursos;
public:
    Matricula();
    Matricula(const Matricula& orig);
    virtual ~Matricula();
    
    void leerAlumnos();
    void imprimirAlumnos();
    void cargarNotas();
    void cargaCursos();
    void imprimirCursos();
};

#endif /* MATRICULA_H */


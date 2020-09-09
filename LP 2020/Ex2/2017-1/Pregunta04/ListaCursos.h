/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCursos.h
 * Author: crimson
 *
 * Created on July 19, 2020, 11:06 PM
 */

#ifndef LISTACURSOS_H
#define LISTACURSOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Curso.h"
#include "NodoCurso.h"
using namespace std;

class ListaCursos {
private:
    class NodoCurso *inicio;
public:
    ListaCursos();
    virtual ~ListaCursos();

    void crear(ifstream&);
    void insertar(const class Curso&);
    void imprimir(ofstream&);
};

#endif /* LISTACURSOS_H */


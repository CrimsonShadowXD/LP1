/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCurso.h
 * Author: crimson
 *
 * Created on July 19, 2020, 11:07 PM
 */

#ifndef NODOCURSO_H
#define NODOCURSO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Curso.h"
#include "ListaCursos.h"
using namespace std;

class NodoCurso {
private:
    class Curso elem;
    class NodoCurso *sig;
public:
    NodoCurso();
    friend class ListaCursos;
};

#endif /* NODOCURSO_H */


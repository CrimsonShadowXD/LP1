/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Superclase.h
 * Author: crimson
 *
 * Created on July 16, 2020, 2:41 PM
 */

#ifndef SUPERCLASE_H
#define SUPERCLASE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

#include "PlPila.h"
#include "Alumno.h"
#include "Profesor.h"
#include "ListaBanco.h"
#include <list>
#include <iterator>
using namespace std;

class Superclase {
private:
    class PlPila<Profesor> lprofesores;
    class PlPila<Alumno> lalumnos;
    class list<ListaBanco> Banco;
public:
    Superclase();
    Superclase(const Superclase& orig);
    virtual ~Superclase();
    void CargarPilas();
    void ImprimirColas();
    void CargarSTL();
    void ImprimirSTL();
};

#endif /* SUPERCLASE_H */


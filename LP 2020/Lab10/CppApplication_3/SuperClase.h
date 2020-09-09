/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SuperClase.h
 * Author: crimson
 *
 * Created on July 15, 2020, 5:23 PM
 */

#ifndef SUPERCLASE_H
#define SUPERCLASE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "PlCola.h"
#include "PlLista.h"
#include "PlPila.h"
#include "Alumno.h"
#include "Profesor.h"
#include "ListaBanco.h"
#include <list>
#include <iterator>
//#include <algorithm>
using namespace std;

class SuperClase {
private:
    PlPila <Alumno> alumnos;
    PlPila <Profesor> profesores;
    vector <ListaBanco> Banco;
public:
    SuperClase();
    SuperClase(const SuperClase& orig);
    virtual ~SuperClase();
    void CargarColas();
    void ImprimirColas();
    void CargarSTL();
    void ImprimirSTL();
};

#endif /* SUPERCLASE_H */


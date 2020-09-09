/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAlumno.h
 * Author: crimson
 *
 * Created on July 7, 2020, 5:18 AM
 */

#ifndef NODOALUMNO_H
#define NODOALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Alumno.h"
#include "ListaAlumnos.h"

using namespace std;

class NodoAlumno {
private:
    class Alumno elem;
    class NodoAlumno *sig;
public:
    NodoAlumno();
    NodoAlumno(const NodoAlumno& orig);
    virtual ~NodoAlumno();
    
    friend class ListaAlumnos;

};

#endif /* NODOALUMNO_H */


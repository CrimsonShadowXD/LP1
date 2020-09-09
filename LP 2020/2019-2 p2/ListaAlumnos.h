/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAlumnos.h
 * Author: crimson
 *
 * Created on July 7, 2020, 5:18 AM
 */

#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoAlumno.h"

using namespace std;

class ListaAlumnos {
private:
    class NodoAlumno *inicio;
public:
    ListaAlumnos();
    ListaAlumnos(const ListaAlumnos& orig);
    virtual ~ListaAlumnos();
    
    void crear(ifstream&);
    void insertar(NodoAlumno*);
    void imprime(ofstream&);
};

#endif /* LISTAALUMNOS_H */


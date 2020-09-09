/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaMiembros.h
 * Author: crimson
 *
 * Created on July 9, 2020, 8:24 PM
 */

#ifndef LISTAMIEMBROS_H
#define LISTAMIEMBROS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoMiembro.h"
#include "Miembro.h"
#include "Administrativo.h"
#include "Docente.h"
#include "Alumno.h"
using namespace std;

class ListaMiembros {
private:
    class NodoMiembro *inicio;
public:
    ListaMiembros();
    ListaMiembros(const ListaMiembros& orig);
    virtual ~ListaMiembros();
    
    void insertar(Miembro *);
    void crear(ifstream&);
    void imp(ofstream&);
    void mod(float f);
};

#endif /* LISTAMIEMBROS_H */


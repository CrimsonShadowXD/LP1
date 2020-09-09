/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: crimson
 *
 * Created on July 10, 2020, 6:35 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Administrativo.h"
#include "Alumno.h"
#include "Docente.h"
#include "Miembro.h"
#include "Npdp.h"

using namespace std;

class Lista {
private:
    class Npdp *inicio;
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    void crear(ifstream&);
    void insertar(Miembro *);
    void imp(ofstream& );
};

#endif /* LISTA_H */


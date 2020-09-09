/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPersonas.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:21 AM
 */

#ifndef LISTAPERSONAS_H
#define LISTAPERSONAS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "NodoPersona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Persona.h"

using namespace std;

class ListaPersonas {
private:
    class NodoPersona *inicio;
public:
    ListaPersonas();
    ListaPersonas(const ListaPersonas& orig);
    virtual ~ListaPersonas();
    
    void imprResultados(int  ,int  ,int  ,int  ,ofstream& );
    void insertar(Persona *);
    void crear(ifstream&);
    void imp(ofstream&);
};

#endif /* LISTAPERSONAS_H */


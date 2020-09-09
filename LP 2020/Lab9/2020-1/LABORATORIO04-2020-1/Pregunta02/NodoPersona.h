/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPersona.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:21 AM
 */

#ifndef NODOPERSONA_H
#define NODOPERSONA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Persona.h"
#include "ListaPersonas.h"

using namespace std;

class NodoPersona {
private:
    class Persona *elem;
    class NodoPersona *sig;
public:
    NodoPersona();
    NodoPersona(const NodoPersona& orig);
    virtual ~NodoPersona();
    friend class ListaPersonas;
};

#endif /* NODOPERSONA_H */


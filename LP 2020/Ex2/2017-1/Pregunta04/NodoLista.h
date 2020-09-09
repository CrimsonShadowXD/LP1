/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.h
 * Author: crimson
 *
 * Created on July 19, 2020, 5:20 PM
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Alumno.h"
#include "Lista.h"
using namespace std;

class NodoLista {
private:
    class Alumno *elem;
    class NodoLista *sig; 
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
    friend class Lista;
};

#endif /* NODOLISTA_H */


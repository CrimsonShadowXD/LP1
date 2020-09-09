/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: crimson
 *
 * Created on July 19, 2020, 5:20 PM
 */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Alumno.h"
#include "Intercambio.h"
#include "Nacional.h"
#include "CursoNotas.h"
#include "NodoLista.h"
using namespace std;

class Lista {
private:
    class NodoLista *inicio;
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();

    void crear(ifstream&);
    void insertar(Alumno*);
    void imprimir(ofstream&);
    
    void BuscarInsertar(ifstream&,int);
};

#endif /* LISTA_H */


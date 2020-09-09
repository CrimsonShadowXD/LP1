/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: crimson
 *
 * Created on July 19, 2020, 1:09 PM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Libro.h"
#include "NodoArbol.h"
using namespace std;

class Arbol {
private:
    class NodoArbol *inicio;
    void insertar(NodoArbol *&, const Libro&);
    void imprimeNodo(NodoArbol*, ofstream&);
    void eliminarNodo(NodoArbol*);
    NodoArbol* buscarNodo(const char *codLib);
public:
    Arbol();
    virtual ~Arbol();
    void crear(ifstream&);
    void imprimir(ofstream&);
    
    void completarAutores(ifstream&);
    void registrarVentas(ifstream&);
    
    bool vacia();
};

#endif /* ARBOL_H */
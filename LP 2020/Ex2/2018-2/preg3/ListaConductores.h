/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:52 AM
 */

#ifndef LISTACONDUCTORES_H
#define LISTACONDUCTORES_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoC.h"
using namespace std;

class ListaConductores {
private:
    class NodoC *inicio;
    class NodoC *ultimo;
public:
    ListaConductores();
    ListaConductores(const ListaConductores& orig);
    virtual ~ListaConductores();
    
    void cargar(ifstream&);
    void insertar(NodoC*);
    void imprimir(ofstream&);
    
    void imprimirRev(ofstream&);
    void imprimirOrden(ofstream&,int);
};

#endif /* LISTACONDUCTORES_H */


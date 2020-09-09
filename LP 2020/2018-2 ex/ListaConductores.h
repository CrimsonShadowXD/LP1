/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.h
 * Author: crimson
 *
 * Created on July 4, 2020, 4:59 PM
 */

#ifndef LISTACONDUCTORES_H
#define LISTACONDUCTORES_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoC.h"
#include "ListaDoble.h"
#include "Infracciones.h"

using namespace std;

class ListaConductores {
private:
    class NodoC *Inicio;
    class NodoC *Fin;
public:
    ListaConductores();
    ListaConductores(const ListaConductores& orig);
    virtual ~ListaConductores();

    void insertar(NodoC *nuevo);
    void crear(ifstream&);
    void imprimir(ofstream&);
    
    void cargarinfracciones(ifstream&);
    void Calc_Impr_Montos(ofstream&,ListaDoble<Infracciones>);
};

#endif /* LISTACONDUCTORES_H */


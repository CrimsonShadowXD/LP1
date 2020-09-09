/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaNotas.h
 * Author: crimson
 *
 * Created on July 7, 2020, 4:31 AM
 */

#ifndef LISTANOTAS_H
#define LISTANOTAS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoNota.h"

using namespace std;

class ListaNotas {
private:
    class NodoNota *inicio;
public:
    ListaNotas();
    ListaNotas(const ListaNotas& orig);
    virtual ~ListaNotas();
    
    void insertar(NodoNota*);
    void leer(ifstream&);
    void imprimir(ofstream&);

};

#endif /* LISTANOTAS_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPallets.h
 * Author: crimson
 *
 * Created on July 9, 2020, 1:18 AM
 */

#ifndef LISTAPALLETS_H
#define LISTAPALLETS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Nodo.h"

using namespace std;

class ListaPallets {
private:
    class Nodo *inicio;
public:
    ListaPallets();
    ListaPallets(const ListaPallets& orig);
    virtual ~ListaPallets();

    void crear(ifstream&);
    void insertar(Nodo*);
    void imprime(ofstream&);
};

#endif /* LISTAPALLETS_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPallet.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:48 PM
 */

#ifndef LISTAPALLET_H
#define LISTAPALLET_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "NodoP.h"
#include "Pallet.h"
#include "PalletUS.h"
#include "PalletPE.h"
#include "PalletEU.h" 
using namespace std;

class ListaPallet {
private:
    class NodoP *inicio,*fin;
    void eliminarNodo(NodoP *&);
public:
    ListaPallet(); 
    virtual ~ListaPallet();

    void crear(ifstream&);
    void insertar(Pallet*);
    void imprimir(ofstream&);
    void eliminar(int);
};

#endif /* LISTAPALLET_H */


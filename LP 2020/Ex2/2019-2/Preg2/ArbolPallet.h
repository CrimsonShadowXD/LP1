/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolPallet.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:37 PM
 */

#ifndef ARBOLPALLET_H
#define ARBOLPALLET_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Pallet.h"
#include "PalletEU.h"
#include "PalletPE.h"
#include "PalletUS.h"
#include "NodoArbol.h"
using namespace std;

class ArbolPallet {
private:
    class NodoArbol *raiz;
    void insertar(NodoArbol*&, Pallet*);
    void imprimeNodo(NodoArbol*, ofstream&);
    void eliminarNodo(NodoArbol*);
    Pallet* extraerDato(NodoArbol*, Pallet*);
    void modificarNodo(NodoArbol*&, Pallet*);
public:
    ArbolPallet();
    ArbolPallet(const ArbolPallet& orig);
    virtual ~ArbolPallet();

    void crear(ifstream&);
    void imprimir(ofstream&);
    Pallet* buscarDato(Pallet*);
    void modificar(Pallet*);
    bool vacia();
};

#endif /* ARBOLPALLET_H */

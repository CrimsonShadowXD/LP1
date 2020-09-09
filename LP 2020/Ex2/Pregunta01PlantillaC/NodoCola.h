/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Nombre: Leandro Lazo La Rosa
 * Codigo: 20130263
 *
 * Created on 10 de diciembre de 2019, 08:08 AM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "PlCola.h"
using namespace std;

template <typename T>
class NodoCola{
public:
    NodoCola();
    friend class PlCola;
private:
    T valor;
    class NodoCola *sig;
};

template <typename T>
NodoCola<T>::NodoCola(){
    sig=NULL;
}

#endif /* NODOCOLA_H */

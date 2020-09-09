/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 10:32 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;

template <typename T> class ArbolBinario;

template <typename T>
class Nodo {
private:
    T dato;
    class Nodo* izq;
    class Nodo* der;
public:
    Nodo();
    friend class ArbolBinario<T>;

};

template <typename T>
Nodo<T>::Nodo(){
    izq = der = NULL;
}
#endif /* NODO_H */


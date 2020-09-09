/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodo.h
 * Author: cueva
 *
 * Created on 14 de julio de 2020, 11:00 AM
 */

#ifndef PLNODO_H
#define PLNODO_H
#include <iostream>
#include "PlLista.h"


template <typename T> class PlLista;

template <typename T>
class PlNodo {
public:
    PlNodo(){sig = NULL;};
    friend class PlLista<T>;    
private:
    T dato;
    PlNodo *sig;
};


#endif /* PLNODO_H */


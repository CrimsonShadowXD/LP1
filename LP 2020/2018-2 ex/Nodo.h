/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: crimson
 *
 * Created on July 5, 2020, 10:56 PM
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaDoble.h"

using namespace std;

template <typename T> class ListaDoble;
template <typename T> 
class Nodo{
    private:
        T elem;        
        Nodo<T> *sig;
        Nodo<T> *ant;
        
        
        
        public:
            Nodo();    
            friend class ListaDoble<T>;
};

template <typename T>
Nodo<T>::Nodo(){
    sig = NULL;
    ant = NULL;
}


#endif /* NODO_H */


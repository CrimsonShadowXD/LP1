/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 09:34 AM
 */
//20150008 Daniela Cisneros
#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

template <typename T> class ColaPrioridad;

template <typename T>
class Nodo {
public:
    Nodo(){
        siguiente=NULL;
    }
    Nodo(const Nodo& orig);

    friend class ColaPrioridad<T>;
    
private:
    T dato;
    class Nodo<T> * siguiente;
};

#endif /* NODO_H */


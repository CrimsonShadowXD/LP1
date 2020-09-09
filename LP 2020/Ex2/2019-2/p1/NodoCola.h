/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.h
 * Author: crimson
 *
 * Created on July 8, 2020, 8:47 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H



#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlCola.h"

using namespace std;
template <typename T>class PlCola;
template <typename T>
class NodoCola{
    private:
        T dato;
        class NodoCola<T> *sig;
    public:
        NodoCola(); 
        friend class PlCola<T>;
};

template <typename T>
NodoCola<T>::NodoCola(){
    sig=NULL;
}

#endif /* NODOCOLA_H */


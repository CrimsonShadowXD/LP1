/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   PlNodoArbol.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 07:48 PM
 */
#include <fstream>
#include <cstring>

using namespace std;
#ifndef PLNODOARBOL_H
#define PLNODOARBOL_H
template <typename T> class PlArbol;
template <typename T>
class PlNodoArbol {
private:
    T dato;
    class PlNodoArbol<T> *izq;
    class PlNodoArbol<T> *der;
public:
    PlNodoArbol();
    friend class PlArbol<T>;
};
template <typename T>
PlNodoArbol<T>::PlNodoArbol(){
    izq = nullptr;
    der = nullptr;
}
#endif /* PLNODOARBOL_H */


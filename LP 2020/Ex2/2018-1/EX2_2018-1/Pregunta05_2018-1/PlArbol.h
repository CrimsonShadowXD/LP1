/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   PlArbol.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 07:49 PM
 */
#include <fstream>
#include <cstring>

using namespace std;
#ifndef PLARBOL_H
#define PLARBOL_H
#include "PlNodoArbol.h"
template <typename T>
class PlArbol {
private:
    class PlNodoArbol<T> *arbol;
    void insertar(class PlNodoArbol<T> *&, T&);
    void eliminaRec(class PlNodoArbol<T> *);
    void imprimeRec(ofstream & , class PlNodoArbol<T> *&);
public:
    PlArbol();
    virtual ~PlArbol();

    void crear(ifstream &);
    void imprimir(ofstream &);
};
template <typename T>
PlArbol<T>::PlArbol(){
    arbol = nullptr;
}
template <typename T>
void PlArbol<T>::crear(ifstream& arch){
    T dato;
    while (1){
        arch>>dato;
        if (arch.eof()) break;
        insertar(arbol,dato);
    }
}
template <typename T>
void PlArbol<T>::eliminaRec(PlNodoArbol<T>* arbol){
    class PlNodoArbol<T> *arbDer;
    if (arbol == nullptr) return;
    eliminaRec(arbol->izq);
    arbDer = arbol->der;
    delete arbol;
    eliminaRec(arbDer);
}
template <typename T>
PlArbol<T>::~PlArbol(){
    eliminaRec(arbol);
    
}
template <typename T>
void PlArbol<T>::insertar(PlNodoArbol<T>*& arbol, T& dato){
    if (arbol == nullptr){
        arbol = new PlNodoArbol<T>;
        arbol->dato = dato;
        return;
    }
    if ( dato < arbol->dato)
        insertar(arbol->izq, dato);
    else insertar(arbol->der,dato);
}

template <typename T>
void PlArbol<T>::imprimir(ofstream&arch){
    imprimeRec(arch,arbol);
}
template <typename T>
void PlArbol<T>::imprimeRec(ofstream & arch, class PlNodoArbol<T> *&arbol){
    if (arbol == nullptr)return;
    imprimeRec(arch,arbol->izq);
    arch<<arbol->dato;
    arch<<endl;
    imprimeRec(arch,arbol->der);
}
#endif /* PLARBOL_H */


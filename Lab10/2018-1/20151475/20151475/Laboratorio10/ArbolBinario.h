/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBinario.h
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:02 AM
 */

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "Nodo.h"
#include "libro.h"
class ArbolBinario {
public:
    ArbolBinario();
    /*Metodos que pueden ser ejecutados por el usuario*/
    void insertar(libro &);
    void modificar(const char*);
    void imprimir(ofstream &arch);
private:
    class Nodo *raiz;
    /*Metodos auxiliares que se encargaran de mantener el encapsulamiento*/
    void inorden(Nodo *nodo, ofstream &arch);
    /*Devuelve el nodo a un libro, por eso se hizo private, porque el usuario
     no puede acceder a los nodos directamente*/
    Nodo *buscar(Nodo *nodo, const char*);
    void insertar(Nodo *&nodo, libro &dato);
};

#endif /* ARBOLBINARIO_H */


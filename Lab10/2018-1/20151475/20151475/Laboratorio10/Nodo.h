/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:20 AM
 */

#ifndef NODO_H
#define NODO_H

#include "libro.h"

/*Nodo de la clase arbol, tendra dato, izquierda y derecha*/
class Nodo {
public:
    Nodo();
    friend class ArbolBinario;
private:
    class libro dato;
    class Nodo *izq;//Puntero al hijo izquierdo
    class Nodo *der;//Puntero al hijo derecho
};

#endif /* NODO_H */


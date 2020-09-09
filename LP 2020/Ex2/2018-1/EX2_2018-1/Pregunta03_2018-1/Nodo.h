/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Nodo.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 04:06 PM
 */
#include <fstream>
#include <cstring>



using namespace std;
#ifndef NODO_H
#define NODO_H
#include "ArbolLibro.h"
#include "Libro.h"
class Nodo {
private:
    class Libro libro;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class ArbolLibro;
};

#endif /* NODO_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 09:19 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
#include "Libro.h"
using namespace std;

class Nodo {
private:
    class Libro libro;
    class Nodo* izq;
    class Nodo* der;
public:
    Nodo();
    friend class ArbolLibros;
};

#endif /* NODO_H */


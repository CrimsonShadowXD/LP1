/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libreria.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 10:12 AM
 */

#ifndef LIBRERIA_H
#define LIBRERIA_H
#include <fstream>
#include "ArbolLibros.h"
using namespace std;

class Libreria {
private:
    class ArbolLibros arbolLibros; 
public:
    Libreria();
    void leer_libros(const char*);
    void completar_autores(const char*);
    void registar_ventas(const char*);
    void imprimir(const char*);
};

#endif /* LIBRERIA_H */


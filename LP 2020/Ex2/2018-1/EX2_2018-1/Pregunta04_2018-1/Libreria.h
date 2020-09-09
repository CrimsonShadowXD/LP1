/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Libreria.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 07:31 PM
 */
#include <fstream>
#include <cstring>
#include "ArbolLibro.h"
using namespace std;
#ifndef LIBRERIA_H
#define LIBRERIA_H

class Libreria {
private:
    class ArbolLibro arbol;

public:
    void crearArbol_E_ImprimeReporte(char **);
};

#endif /* LIBRERIA_H */


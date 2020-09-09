/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   ArbolLibro.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 04:06 PM
 */
#include <fstream>
#include <cstring>
#include "Nodo.h"
using namespace std;
#ifndef ARBOLLIBRO_H
#define ARBOLLIBRO_H

class ArbolLibro {
private:
    class Nodo *arbol;
    void insertar(class Libro &, class Nodo*&);
    Nodo *buscarLibro(char *);
    void imprimeRec(ofstream &, class Nodo*, int &);
    void eliminaRec(class Nodo*&);
public:
    ArbolLibro();
    virtual ~ArbolLibro();

    void crear(ifstream &);
    void completarAutores(ifstream&);
    void registrarVentas(ifstream&);
    void reporte(ofstream &);
    void eliminaArbol(void);
};

#endif /* ARBOLLIBRO_H */


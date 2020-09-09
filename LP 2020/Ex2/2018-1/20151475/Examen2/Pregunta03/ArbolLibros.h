/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolLibros.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 09:21 AM
 */

#ifndef ARBOLLIBROS_H
#define ARBOLLIBROS_H
#include <fstream>
#include "Nodo.h"
using namespace std;

class ArbolLibros {
private:
    class Nodo *raiz;
    
    void inorden(Nodo* nodo, ofstream &arch);
    void insertarAux(Nodo *&nodo, const char *cod, const char*tit, 
                     double precio);
    void impLinea(ofstream &arch, char c, int tam);
    void eliminarAux(Nodo *nodo);
public:
    ArbolLibros();
    void insertar(const char *cod, const char*tit, double precio);
    void imprimir(ofstream &arch);
    void incrementar_ventas(const char*);
    void insertar_autor(int dni, const char*nomb, const char*codLib);
    void eliminar();
};

#endif /* ARBOLLIBROS_H */


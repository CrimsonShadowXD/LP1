/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorAutores.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 08:12 AM
 */
//20150008 Daniela Cisneros
#ifndef GESTORAUTORES_H
#define GESTORAUTORES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaAuthor.h"
#include "Paper.h"
using namespace std;

class GestorAutores {
public:
    GestorAutores();
    GestorAutores(const GestorAutores& orig);
    virtual ~GestorAutores();
    void leerAuthors(const char*);
    void leerPapers(const char*);
    void imprimirReporte(const char*);
    void insertarPaper(int, Paper *);
    void eliminarLista();
private:
    ListaAuthor lstAuthors;
};

#endif /* GESTORAUTORES_H */


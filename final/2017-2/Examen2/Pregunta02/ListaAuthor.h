/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAuthor.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 08:13 AM
 */
//20150008 Daniela Cisneros
#ifndef LISTAAUTHOR_H
#define LISTAAUTHOR_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NodoAuthor.h"
#include "Author.h"
#include "Paper.h"
using namespace std;

class ListaAuthor {
public:
    ListaAuthor();
    ListaAuthor(const ListaAuthor& orig);
    virtual ~ListaAuthor();
    void imprimir(ostream &);
    void eliminar();
    void insertar(Author &);
    void insertarPaper(int, Paper*);
    
private:
    class NodoAuthor* lista;

};

#endif /* LISTAAUTHOR_H */


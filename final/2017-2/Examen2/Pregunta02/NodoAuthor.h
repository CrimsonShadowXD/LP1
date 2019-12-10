/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAuthor.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 08:13 AM
 */
//20150008 Daniela Cisneros
#ifndef NODOAUTHOR_H
#define NODOAUTHOR_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaAuthor.h"
#include "Author.h"
#include "ListaPaper.h"
#include "Paper.h"
using namespace std;

class NodoAuthor {
public:
    NodoAuthor();
    NodoAuthor(const NodoAuthor& orig);
    virtual ~NodoAuthor();
    friend class ListaAuthor;
private:
    class Author dato;
    class ListaPaper lstPapers;
    class NodoAuthor * sig;
};

#endif /* NODOAUTHOR_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPaper.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 10:24 AM
 */
//20150008 Daniela Cisneros
#ifndef LISTAPAPER_H
#define LISTAPAPER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Paper.h"
#include "NodoPaper.h"
using namespace std;

class ListaPaper {
public:
    ListaPaper();
    ListaPaper(const ListaPaper& orig);
    virtual ~ListaPaper();
    void imprimir(ostream &);
    void eliminar();
    void insertar(Paper*);
private:
    class NodoPaper* lista;
    
};

#endif /* LISTAPAPER_H */


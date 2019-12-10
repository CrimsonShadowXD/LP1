/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorPublicaciones.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 09:08 AM
 */
//20150008 Daniela Cisneros
#ifndef GESTORPUBLICACIONES_H
#define GESTORPUBLICACIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaPaper.h"
using namespace std;


class GestorPublicaciones {
public:
    GestorPublicaciones();
    GestorPublicaciones(const GestorPublicaciones& orig);
    virtual ~GestorPublicaciones();
    void leerPapers(const char*);
    void imprimirReporte(const char*);
private:
    ListaPaper lstPapers;
};

#endif /* GESTORPUBLICACIONES_H */


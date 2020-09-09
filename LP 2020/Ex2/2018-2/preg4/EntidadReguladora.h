/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntidadReguladora.h
 * Author: crimson
 *
 * Created on July 20, 2020, 8:17 AM
 */

#ifndef ENTIDADREGULADORA_H
#define ENTIDADREGULADORA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaConductores.h"
#include "NodoC.h"
#include "PlListaDoble.h"
#include "Infraccion.h"
using namespace std;

class EntidadReguladora {
private:
    class ListaConductores conductores;
    class PlListaDoble<Infraccion> infracciones;
public:
    EntidadReguladora();
    EntidadReguladora(const EntidadReguladora& orig);
    virtual ~EntidadReguladora();
    void cargarCond();
    void cargarInfr();
    void imprimirMontos();
    
    void impPersonaMonto(ofstream&,int);

};

#endif /* ENTIDADREGULADORA_H */


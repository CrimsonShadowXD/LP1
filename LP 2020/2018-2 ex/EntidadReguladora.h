/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntidadReguladora.h
 * Author: crimson
 *
 * Created on July 6, 2020, 12:19 AM
 */

#ifndef ENTIDADREGULADORA_H
#define ENTIDADREGULADORA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaConductores.h"
#include "ListaDoble.h"
#include "Infracciones.h"

using namespace std;

class EntidadReguladora {
private:
    ListaConductores cond;
    ListaDoble<Infracciones> infr;
public:
    EntidadReguladora();
    EntidadReguladora(const EntidadReguladora& orig);
    virtual ~EntidadReguladora();
    
    void ProcesarDatos();
};

#endif /* ENTIDADREGULADORA_H */


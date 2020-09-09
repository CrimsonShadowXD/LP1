/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regular.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 09:37 PM
 */
#include <fstream>
#include "Alumno.h"

using namespace std;

#ifndef REGULAR_H
#define REGULAR_H

class Regular: public Alumno {
public:
    Regular();
    virtual ~Regular();
    
    void setEspecialidad(char* entrada);
    void setFacultad(char* entrada);
    
    char* getEspecialidad();
    char* getFacultad();
    
    char getTipo();    
    
    void imprimir(ofstream &out);
    void leer(ifstream &in);
    
private:
    char* especialidad;
    char* facultad;
};

#endif /* REGULAR_H */


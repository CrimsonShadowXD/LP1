/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.h
 * Author: crimson
 *
 * Created on July 9, 2020, 6:56 PM
 */

#ifndef DOCENTE_H
#define DOCENTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Miembro.h"

using namespace std;

class Docente:public Miembro {
private:
    char *categoria;
    char *dedicacion;
    char *seccion;
    char *grado;
    double sueldo;
public:
    Docente();
    Docente(const Docente& orig);
    virtual ~Docente();
    
    void setSueldo(double sueldo);
    double getSueldo() const;
    void setGrado(const char*  );
    void getGrado(char*) const;
    void setSeccion(const char*    );
    void getSeccion(char*) const;
    void setDedicacion(const char*  );
    void getDedicacion(char*) const;
    void setCategoria(const char*  );
    void getCategoria(char*) const;    

    void leer(ifstream&);
    void imprimir(ofstream&);
    void getTipo();
    void modificar(float);
};

#endif /* DOCENTE_H */


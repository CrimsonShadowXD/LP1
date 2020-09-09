/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrativo.h
 * Author: crimson
 *
 * Created on July 9, 2020, 6:57 PM
 */

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Miembro.h"

using namespace std;

class Administrativo:public Miembro {
private:
    char *puesto;
    char *gradoDeInstruccion;
    int aDeServ;
    double sueldo;
public:
    Administrativo();
    Administrativo(const Administrativo& orig);
    virtual ~Administrativo();
    
    void setSueldo(double sueldo);
    double getSueldo() const;
    void setADeServ(int aDeServ);
    int getADeServ() const;
    void setGradoDeInstruccion(const char*  );
    void getGradoDeInstruccion(char*) const;
    void setPuesto(const char*  );
    void getPuesto(char*) const;

    void leer(ifstream&);
    void imprimir(ofstream&);
    void getTipo();
    void modificar(float);
};

#endif /* ADMINISTRATIVO_H */


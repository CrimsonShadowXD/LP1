/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 9, 2020, 6:56 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Miembro.h"

using namespace std;

class Alumno:public Miembro {
private:
    char *especalidad;
    char *facultad;
    int escalaDePago;
    double valorDelCredito;
    double creditosAprobados;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();

    void setCreditosAprobados(double creditosAprobados);
    double getCreditosAprobados() const;
    void setValorDelCredito(double valorDelCredito);
    double getValorDelCredito() const;
    void setEscalaDePago(int escalaDePago);
    int getEscalaDePago() const;
    void setFacultad(const char*  );
    void getFacultad(char*) const;
    void setEspecalidad(const char*  );
    void getEspecalidad(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    void getTipo();
    void modificar(float);
};

ifstream &operator >> (ifstream &,Alumno &);
ofstream &operator << (ofstream &,Alumno &);

#endif /* ALUMNO_H */


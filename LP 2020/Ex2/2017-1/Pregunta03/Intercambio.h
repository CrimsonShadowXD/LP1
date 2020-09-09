/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.h
 * Author: crimson
 *
 * Created on July 19, 2020, 3:54 PM
 */

#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>
#include <iterator>
#include "Alumno.h"
using namespace std;

class Intercambio : public Alumno {
private:
    char *pais,*idioma;
    int semestres;
    list <CursoNotas> notas;
public:
    Intercambio();
    Intercambio(const Intercambio& orig);
    virtual ~Intercambio();

    void setSemestres(int semestres);
    int getSemestres() const;
    void setIdioma(const char*  );
    void getIdioma(char*) const;
    void setPais(const char*  );
    void getPais(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    char getTipo();
    void insertarNota(const CursoNotas&);
    void imprimirNotas(ofstream&);
};

#endif /* INTERCAMBIO_H */


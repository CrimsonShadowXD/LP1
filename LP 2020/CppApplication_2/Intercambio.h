/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.h
 * Author: crimson
 *
 * Created on July 3, 2020, 12:50 AM
 */

#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Alumno.h"
using namespace std;

class Intercambio:public Alumno {
private:
    char *pais;
    char *idioma;
    int tiempo;
public:
    Intercambio();
    Intercambio(const Intercambio& orig);
    virtual ~Intercambio();
    void SetTiempo(int tiempo);
    int GetTiempo() const;
    void SetIdioma(char*);
    void GetIdioma(char*) const;
    void SetPais(char*);
    void GetPais(char*) const;

};

#endif /* INTERCAMBIO_H */


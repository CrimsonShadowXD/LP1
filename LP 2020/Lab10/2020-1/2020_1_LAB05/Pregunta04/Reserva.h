/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reserva.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 09:09 AM
 */

#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Aula.h"
#include "PlCola.h"
#include "Alumno.h"
#include "Profesor.h"
using namespace std;

class Reserva {
private:
    vector <Aula> vAula;
    class PlCola <Alumno> cAlumno;
    class PlCola <Profesor> cProfesor;
public:
    Reserva();
    Reserva(const Reserva& orig);
    virtual ~Reserva();
    
    void cargarPilas(ifstream&);
    void cargarSTL(ifstream&);
    void carga(char*,char*);
    void imprimirPila();
    void imprimirSTL();
    void asigna(int);
    void imprimirAulas();
};

#endif /* RESERVA_H */


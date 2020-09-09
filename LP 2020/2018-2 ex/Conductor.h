/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: crimson
 *
 * Created on July 4, 2020, 4:57 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaVehiculos.h"

using namespace std;

class Conductor {
private:
    int dni;
    char *nombre;
    int telefono;
    ListaVehiculos vehiculos;
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    bool operator >(Conductor);
    void setTelefono(int telefono);
    int getTelefono() const;
    void setNombre(char* );
    void getNombre(char*) const;
    void setDni(int dni);
    int getDni() const;
    
    void cargaInfracc(char*,int);
    void ObtenerM();
};

#endif /* CONDUCTOR_H */


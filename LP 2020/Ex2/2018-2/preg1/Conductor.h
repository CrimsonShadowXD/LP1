/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:53 AM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Conductor {
private:
    int dni,telefono;
    char *nombre;
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetDni(int dni);
    int GetDni() const;

    void leer(ifstream&);
    void imprimir(ofstream&);
};

#endif /* CONDUCTOR_H */


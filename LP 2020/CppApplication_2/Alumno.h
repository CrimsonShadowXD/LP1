/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 3, 2020, 12:49 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Alumno {
private:
    char *nombre;
    int codigo;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char*);
    void GetNombre(char*) const;

};

#endif /* ALUMNO_H */


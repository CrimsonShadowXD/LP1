/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 19, 2020, 3:54 PM
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
    int codigo;
    char *nombre;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void leer(ifstream&)=0;
    virtual void imprimir(ofstream&)=0;
    virtual char getTipo()=0;
    
};

#endif /* ALUMNO_H */


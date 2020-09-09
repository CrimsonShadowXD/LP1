/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:02 AM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Persona {
private:
    char *nombre;
    int codigo;
    char *distrito;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetDistrito(const char*);
    void GetDistrito(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(const char*);
    void GetNombre(char *) const;
    
    virtual void leer(ifstream&)=0;
    virtual void imprimir(ofstream&)=0;
    virtual int getPrio()=0;
    
};

#endif /* PERSONA_H */


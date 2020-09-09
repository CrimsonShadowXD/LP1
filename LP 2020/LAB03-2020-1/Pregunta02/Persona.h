/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:06 AM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <iomanip>
#include <fstream>
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
    void SetDistrito(char*to);
    void GetDistrito(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char*);
    void GetNombre(char*) const;
};

#endif /* PERSONA_H */


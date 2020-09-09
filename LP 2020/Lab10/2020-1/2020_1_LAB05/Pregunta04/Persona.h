/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:04 AM
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
    char *nombre,*distrito;
    int codigo;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetDistrito(const char*  );
    void GetDistrito(char*) const;
    void SetNombre(const char*  );
    void GetNombre(char*) const;
};

#endif /* PERSONA_H */


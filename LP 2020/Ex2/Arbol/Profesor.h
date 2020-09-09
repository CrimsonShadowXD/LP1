/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:05 AM
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Persona.h"
using namespace std;

class Profesor : public Persona {
private:
    char *categoria,*dedicacion,*seccion,*grado;
public:
    Profesor();
    Profesor(const Profesor& orig);
    virtual ~Profesor();
    void SetGrado(const char*  );
    void GetGrado(char*) const;
    void SetSeccion(const char*  );
    void GetSeccion(char*) const;
    void SetDedicacion(const char*  );
    void GetDedicacion(char*) const;
    void SetCategoria(const char*  );
    void GetCategoria(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    
    void operator=(const Profesor&);
    bool operator==(const Profesor&);
    bool operator>(const Profesor&);
    bool operator<(const Profesor&);
};

ofstream& operator<<(ofstream&, Profesor&);
void operator>>(ifstream&, Profesor&);
#endif /* PROFESOR_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: cueva
 *
 * Created on 5 de julio de 2020, 08:08 PM
 */
#include <fstream>
using namespace std;



#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    int dni;
    char *nombre;
public:
    Persona();
    Persona(const Persona &);
    virtual ~Persona();
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    virtual char mostrarclase()=0;
    virtual void lee(ifstream &)=0;
    virtual void imprime(ofstream &)=0;
};



#endif /* PERSONA_H */


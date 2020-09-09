/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: cueva
 *
 * Created on 14 de julio de 2020, 10:10 AM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <fstream>
using namespace std;

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
};


#endif /* PERSONA_H */


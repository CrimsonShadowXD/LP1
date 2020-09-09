
/* 
 * File:   Alumno.h
 * Author: Rodrigo Agama    Codigo:20151460
 *
 * Created on 3 de julio de 2020, 08:06
 */
#include "Persona.h"
#include <fstream>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno: public Persona {
private:
    int escala;
    char* especialidad;
    char* facultad;

public:
    Alumno();
    Alumno(const Alumno &orig);
    virtual ~Alumno();
    void SetFacultad(char* facultad);
    char* GetFacultad() const;
    void SetEspecialidad(char* especialidad);
    char* GetEspecialidad() const;
    void SetEscala(int escala);
    int GetEscala() const;
    
    void operator=(Alumno &in);
    void leer(ifstream &in);
    void imprimir(ofstream &out);
    
};

#endif /* ALUMNO_H */


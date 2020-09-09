
/* 
 * File:   Miembro.h
 * Author: Rodrigo Agama    Codigo:20151460
 *
 * Created on 3 de julio de 2020, 08:06
 */
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include <fstream>

using namespace std;

#ifndef MIEMBRO_H
#define MIEMBRO_H

class Miembro {
private:
    class Alumno* lalumno;
    class Profesor* lprofesor;
public:
    Miembro();
    virtual ~Miembro();
    void leerMiembro(ifstream &in);
    void agregarAlumno(Alumno &entrada);
    void agregarProfesor(Profesor &entrada);
    
    void operator+(Alumno &entrada);
    void operator+(Profesor &entrada);
    
    void imprimir(char *nombreA, char *nombreP);    
};

#endif /* MIEMBRO_H */


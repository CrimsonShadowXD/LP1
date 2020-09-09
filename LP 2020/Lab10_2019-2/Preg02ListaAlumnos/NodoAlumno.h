
/* 
 * File:   NodoAlumno.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 6 de julio de 2020, 19:26
 */
#include "BaseAlum.h"
#include "Alumno.h"

#ifndef NODOALUMNO_H
#define NODOALUMNO_H

class NodoAlumno {
private:
    Alumno elem;
    NodoAlumno *sig;
    
    friend class ListaAlumnos;    

public:
    NodoAlumno();
    virtual ~NodoAlumno();


};

#endif /* NODOALUMNO_H */


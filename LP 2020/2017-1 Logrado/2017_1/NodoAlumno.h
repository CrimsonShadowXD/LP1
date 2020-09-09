/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAlumno.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 10:20 PM
 */

#include "Alumno.h"
#include "CursoNota.h"
#include <list>

#ifndef NODOALUMNO_H
#define NODOALUMNO_H

class NodoAlumno {
public:
    NodoAlumno();
    virtual ~NodoAlumno();
private:
    class Alumno *elem;
    list<CursoNota> notas;
    
    NodoAlumno *sig;    
    
    friend class ListaAlumnos;
};

#endif /* NODOALUMNO_H */


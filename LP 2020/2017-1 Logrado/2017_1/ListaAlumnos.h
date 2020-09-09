/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAlumnos.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 10:36 PM
 */
#include "Alumno.h"
#include "Curso.h"
#include "NodoAlumno.h"
#include <iostream>

using namespace std;

#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

class ListaAlumnos {
public:
    ListaAlumnos();
    virtual ~ListaAlumnos();
    
    NodoAlumno* buscarAlumno(int prueba);
    void imprimirAlumno(ofstream &out, int codigo);
    
    void insertar(NodoAlumno *nuevo);
    
    void leerAlumnos(ifstream &in);
    void leerNotas(ifstream &in);
    void imprimir(ofstream &out);    
    
    bool verificarAprobado(int codigoAlumno,char **&intencion);    
    
private:
    NodoAlumno *lista;
};

#endif /* LISTAALUMNOS_H */


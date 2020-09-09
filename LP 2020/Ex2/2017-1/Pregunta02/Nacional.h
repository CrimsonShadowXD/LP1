/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nacional.h
 * Author: crimson
 *
 * Created on July 19, 2020, 3:54 PM
 */

#ifndef NACIONAL_H
#define NACIONAL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <list>
#include <iterator>
#include "Alumno.h"
using namespace std;

class Nacional : public Alumno {
private:
    char *especialidad,*facultad;    
    list <CursoNotas> notas;
public:
    Nacional();
    Nacional(const Nacional& orig);
    virtual ~Nacional();

    void setFacultad(const char*  );
    void getFacultad(char*) const;
    void setEspecialidad(const char*  );
    void getEspecialidad(char*) const;  
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    char getTipo();
    void insertarNota(const CursoNotas&);
    void imprimirNotas(ofstream&);
};

#endif /* NACIONAL_H */


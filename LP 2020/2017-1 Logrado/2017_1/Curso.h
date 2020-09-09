/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: Rodrigo
 *
 * Created on 9 de diciembre de 2019, 12:14 AM
 */
#include <vector>
#include <fstream>

using namespace std;

#ifndef CURSO_H
#define CURSO_H

class Curso {
public:
    Curso();
    virtual ~Curso();
    
    void setCodigo(char *entrada);
    void setNombre(char* entrada);
    void setCreditos(double entrada);
    
    char* getCodigo();
    char* getNombre();
    double getCreditos();
    
    char** getRequisitos();
    
    void leer(ifstream &in);
    void imprimir(ofstream &out);
    
private:
    char *codigo;
    char *nombre;
    double creditos;
    vector<char*> requisitos;

};

#endif /* CURSO_H */


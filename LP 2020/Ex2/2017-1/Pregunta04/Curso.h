/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: crimson
 *
 * Created on July 19, 2020, 8:40 PM
 */

#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Curso {
private:
    char *codigo,*nombre;
    double creditos;
    vector <char*> requisitos;
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetCodigo(const char*  );
    void GetCodigo(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    void insertarReq(const char*);
    void imprimirReq(ofstream&);
    
    void operator=(const Curso& );
    bool operator==(const Curso&);
    bool operator>(const Curso&);
    bool operator<(const Curso&);

};
ofstream& operator<<(ofstream&, Curso&);
void operator>>(ifstream&, Curso&);

#endif /* CURSO_H */


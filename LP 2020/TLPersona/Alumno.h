/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: cueva
 *
 * Created on 14 de julio de 2020, 10:31 AM
 */
#ifndef ALUMNO_H
#define ALUMNO_H
#include <fstream>
#include "Persona.h"

using namespace std;

class Alumno: public Persona {
private:
    int codigoa;
    int escala;
    
public:
    Alumno();
    int GetCodigoa() const; 
    void SetCodigoa(int codigoa);
    int GetEscala() const;
    void SetEscala(int escala);
    char mostrarclase(void);
    void lee(ifstream &);
    void imprime(ofstream &);
    void operator=(const Alumno&);
    bool operator>(const Alumno&);
 
};
    

void operator >> (ifstream &,Alumno &);
void operator << (ofstream &,Alumno &);

#endif /* ALUMNO_H */


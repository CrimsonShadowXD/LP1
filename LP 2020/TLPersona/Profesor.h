/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: cueva
 *
 * Created on 14 de julio de 2020, 10:32 AM
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include <fstream>
#include "Persona.h"

using namespace std;

class Profesor:public Persona {
private:
    char * codigop;
    int dedicacion; //1: TC 2: TPA 3:TCM
    int antiguedad; 
public:
    Profesor();
    void GetCodigop(char *) const;
    void SetCodigop(char* codigop);
    int GetAntiguedad() const;
    void SetAntiguedad(int );
    int GetDedicacion() const;
    void SetDedicacion(int tipo);
    char mostrarclase(void);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void operator=(const Profesor &);
    bool operator>(const Profesor &);
};

void operator >> (ifstream &,Profesor&);
void operator << (ofstream &,Profesor&);

#endif /* PROFESOR_H */


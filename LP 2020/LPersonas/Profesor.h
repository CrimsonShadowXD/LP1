/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: cueva
 *
 * Created on 7 de julio de 2020, 11:01 AM
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
    char* GetCodigop() const;
    void SetCodigop(char* codigop);
    int GetAntiguedad() const;
    void SetAntiguedad(int );
    int GetDedicacion() const;
    void SetDedicacion(int tipo);
    char mostrarclase(void);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* PROFESOR_H */


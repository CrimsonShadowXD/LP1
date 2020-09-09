/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 16, 2020, 1:26 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Persona.h"

using namespace std;

class Alumno:public Persona {
private:
    int escala;
    char *esp,*fac;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetFac(const char*  );
    void GetFac(char*) const;
    void SetEsp(const char*  );
    void GetEsp(char*) const;
    void SetEscala(int escala);
    int GetEscala() const;
    void operator=(const Alumno& );
    bool operator>(const Alumno&);
    bool operator<(const Alumno&);

};
ofstream& operator<<(ofstream&, Alumno&);
void operator>>(ifstream&, Alumno&);

#endif /* ALUMNO_H */


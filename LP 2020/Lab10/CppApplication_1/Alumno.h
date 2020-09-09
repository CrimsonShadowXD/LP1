/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: crimson
 *
 * Created on July 15, 2020, 4:48 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Alumno {
private:
    int cod,escala;
    char *nom;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetNom(const char*  );
    void GetNom(char*) const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetCod(int cod);
    int GetCod() const;
    
    void operator=(const Alumno& );
};

ofstream& operator<<(ofstream&, Alumno&);
void operator>>(ifstream&, Alumno&);

#endif /* ALUMNO_H */


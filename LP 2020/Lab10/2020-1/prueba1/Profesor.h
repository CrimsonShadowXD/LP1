/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: crimson
 *
 * Created on July 16, 2020, 1:26 PM
 */

#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Persona.h"

using namespace std;

class Profesor:public Persona {
private:
    char *cate,*dedi,*secc,*grado;
public:
    Profesor();
    Profesor(const Profesor& orig);
    virtual ~Profesor();
    void SetGrado(const char*  );
    void GetGrado(char*) const;
    void SetSecc(const char*  );
    void GetSecc(char*) const;
    void SetDedi(const char*    );
    void GetDedi(char*) const;
    void SetCate(const char*  );
    void GetCate(char*) const;

    void operator=(const Profesor&);
    bool operator>(const Profesor&);
    bool operator<(const Profesor&);
};
ofstream& operator<<(ofstream&, Profesor&);
void operator>>(ifstream&, Profesor&);

#endif /* PROFESOR_H */


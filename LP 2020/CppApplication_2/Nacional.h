/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nacional.h
 * Author: crimson
 *
 * Created on July 3, 2020, 12:50 AM
 */

#ifndef NACIONAL_H
#define NACIONAL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Alumno.h"

using namespace std;

class Nacional:public Alumno {
private:
    char *especialidad;
    char *facultad;
public:
    Nacional();
    Nacional(const Nacional& orig);
    virtual ~Nacional();
    void SetFacultad(char*);
    void GetFacultad(char*) const;
    void SetEspecialidad(char*);
    void GetEspecialidad(char*) const;

};

#endif /* NACIONAL_H */


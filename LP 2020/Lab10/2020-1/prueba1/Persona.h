/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: crimson
 *
 * Created on July 16, 2020, 1:26 PM
 */

#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Persona {
private:
    char *nom,*dist;
    int cod;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetCod(int cod);
    int GetCod() const;
    void SetDist(const char*  );
    void GetDist(char*) const;
    void SetNom(const char*  );
    void GetNom(char*) const;

};

#endif /* PERSONA_H */


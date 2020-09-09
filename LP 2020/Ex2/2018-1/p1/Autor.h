/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.h
 * Author: crimson
 *
 * Created on July 12, 2020, 9:50 PM
 */

#ifndef AUTOR_H
#define AUTOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Autor {
private:
    int dni;
    char *nom;
public:
    Autor();
    Autor(const Autor& orig);
    virtual ~Autor();
    void SetNom(const char*);
    void GetNom(char*) const;
    void SetDni(int dni);
    int GetDni() const;

    //
};

#endif /* AUTOR_H */


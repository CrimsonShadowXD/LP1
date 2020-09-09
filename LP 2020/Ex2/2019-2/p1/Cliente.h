/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: crimson
 *
 * Created on July 14, 2020, 12:06 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Cliente {
private:
    int dni,hini;
    double tiempo;
    char *nom;
public:
    Cliente();
    virtual ~Cliente();
    void SetNom(const char*  );
    void GetNom(char*) const;
    void SetTiempo(double tiempo);
    double GetTiempo() const;
    void SetHini(int hini);
    int GetHini() const;
    void SetDni(int dni);
    int GetDni() const;

    void operator =(const Cliente&cli);
};

ofstream& operator<<(ofstream&,Cliente&);
void operator>>(ifstream&,Cliente&);

#endif /* CLIENTE_H */


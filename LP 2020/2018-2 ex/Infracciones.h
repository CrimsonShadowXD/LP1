/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infracciones.h
 * Author: crimson
 *
 * Created on July 5, 2020, 11:10 PM
 */

#ifndef INFRACCIONES_H
#define INFRACCIONES_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Infracciones {
private:
    int cod;
    char *Desc;
    char *Grav;
    float monto;
public:
    Infracciones();
    Infracciones(const Infracciones& orig);
    virtual ~Infracciones();

    void leer(ifstream&);
    void imprimir(ofstream&);
    bool operator >(Infracciones infr);
    
    void setMonto(float monto);
    float getMonto() const;
    void setGrav(char* );
    void getGrav(char*) const;
    void setDesc(char* );
    void getDesc(char*) const;
    void setCod(int cod);
    int getCod() const;
};

#endif /* INFRACCIONES_H */


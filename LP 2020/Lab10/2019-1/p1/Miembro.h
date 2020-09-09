/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.h
 * Author: crimson
 *
 * Created on July 9, 2020, 6:55 PM
 */

#ifndef MIEMBRO_H
#define MIEMBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Miembro {
private:
    char *nombre;
    int codigo;
    char *distrito;
public:
    Miembro();
    Miembro(const Miembro& orig);
    virtual ~Miembro();

    void setDistrito(const char*  );
    void getDistrito(char*) const;
    void setCodigo(int codigo);
    int getCodigo() const;
    void setNombre(const char*  );
    void getNombre(char*) const;
    
        
    virtual void leer(ifstream&)=0;
    virtual void imprimir(ofstream&)=0;
    virtual void getTipo()=0;
    virtual void modificar(float)=0;

};

#endif /* MIEMBRO_H */


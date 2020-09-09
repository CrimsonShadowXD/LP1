/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 09:37 PM
 */
#include <fstream>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    
    void setCodigo(int entrada);
    int getCodigo();
    
    void setNombre(char* entrada);
    char* getNombre();
    
    bool operator<(Alumno &b);
    bool operator==(Alumno &b);
    bool operator>(Alumno &b);
    
    virtual void leer(ifstream &in);
    virtual void imprimir(ofstream &out)=0;    
    virtual char getTipo()=0;
    
private:
    int codigo;
    char *nombre;

};

#endif /* ALUMNO_H */


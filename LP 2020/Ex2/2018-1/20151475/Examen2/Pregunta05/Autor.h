/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 08:12 AM
 */

#ifndef AUTOR_H
#define AUTOR_H

#include <fstream>
using namespace std;
class Autor {
private:
    int dni;
    char *nombre;
public:
    Autor();
    Autor(const Autor& orig);
    virtual ~Autor();
    /*Set y get*/
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    
    /*Operadores sobrecargados*/
    bool operator <(const Autor & aut);
    bool operator ==(const Autor & aut);
    bool operator >(const Autor & aut);
    friend ifstream &operator >>(ifstream & in, Autor &);
    friend ofstream &operator <<(ofstream & out, const Autor & aut);
    void operator =(const Autor & aut);
};

#endif /* AUTOR_H */


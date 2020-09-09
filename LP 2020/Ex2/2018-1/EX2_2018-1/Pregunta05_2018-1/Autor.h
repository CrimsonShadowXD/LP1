/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Autor.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 02:32 PM
 */
#include <fstream>
#include <cstring>

using namespace std;
#ifndef AUTOR_H
#define AUTOR_H

class Autor {
private:
    int dni;
    char* nombre;
public:
    Autor();
    Autor(const Autor& orig);
    virtual ~Autor();
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;

    void operator=(const class Autor&);
    bool operator<(const class Autor&);

};
void operator>>(ifstream &,class Autor &);
void operator<<(ofstream &, const class Autor &);
#endif /* AUTOR_H */


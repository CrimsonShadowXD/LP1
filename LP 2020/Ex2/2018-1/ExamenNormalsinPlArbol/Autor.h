/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.h
 * Author: crimson
 *
 * Created on July 18, 2020, 3:24 PM
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
    char*nombre;
public:
    Autor();
    Autor(const Autor& orig);
    virtual ~Autor();
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void operator=(const Autor& );
    bool operator==(const Autor&);
    bool operator>(const Autor&);
    bool operator<(const Autor&);

};
ofstream& operator<<(ofstream&, Autor&);
void operator>>(ifstream&, Autor&);

#endif /* AUTOR_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: crimson
 *
 * Created on July 12, 2020, 10:29 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Autor.h"
#include "list"
#include "iterator"

using namespace std;

class Libro {
private:
    char *codigo;
    char *titulo;
    double precio;
    list <Autor> autores;
    int nVend;
    double monto;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetMonto(double monto);
    double GetMonto() const;
    void SetNVend(int nVend);
    int GetNVend() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetTitulo(const char*  );
    void GetTitulo(char*) const;
    void SetCodigo(const char*  );
    void GetCodigo(char*) const;
    
    void operator ++(void);
    void operator ++(int);
    void operator=(const Libro&);
};
ofstream& operator<<(ofstream&, Libro&);
void operator>>(ifstream&, Libro&);

#endif /* LIBRO_H */


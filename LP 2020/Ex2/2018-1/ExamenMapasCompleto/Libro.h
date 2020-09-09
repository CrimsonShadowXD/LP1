/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: crimson
 *
 * Created on July 18, 2020, 3:40 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <map>
#include <iterator>
#include "Autor.h"
using namespace std;

class Libro {
private:
    char *codigo,*titulo;
    double precio,monto;
    int nVend;
    map <int,Autor> autores;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetNVend(int nVend);
    int GetNVend() const;
    void SetMonto(double monto);
    double GetMonto() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetTitulo(const char*  );
    void GetTitulo(char*) const;
    void SetCodigo(const char*  );
    void GetCodigo(char*) const;
    void MeterLibro(const Autor&);
    void ImprimirAutores(ofstream&);

    void operator++(void);
    void operator=(const Libro& );
    bool operator==(const Libro&);
    bool operator>(const Libro&);
    bool operator<(const Libro&);
};
ofstream& operator<<(ofstream&, Libro&);
void operator>>(ifstream&, Libro&);
#endif /* LIBRO_H */


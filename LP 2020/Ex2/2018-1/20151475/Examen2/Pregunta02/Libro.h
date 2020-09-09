/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 08:30 AM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <list>
#include <fstream>
#include "Autor.h"  
using namespace std;

class Libro {
private:
    char *codigo;
    char *titulo;
    list < Autor > autores;
    double precio;
    int nVend;
    double monto;
    
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    /*Set y get*/
    void SetMonto(double monto);
    double GetMonto() const;
    void SetNVend(int nVend);
    int GetNVend() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char *) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    void SetAutor(int dni, const char *nomb);
    void GetAutor(int &dni, char *nomb, int pos);
    /*operadores sobrecargados*/
    bool operator <(const Libro& lib);
    bool operator >(const Libro& lib);
    bool operator ==(const Libro& lib);
    void operator =(const Libro & lib);
    friend ifstream & operator >>(ifstream & in, Libro & lib);
    void operator ++(void);
    void operator ++(int);
    friend ofstream & operator <<(ofstream &out, Libro &lib);
    /*Funciones extra*/
};

#endif /* LIBRO_H */


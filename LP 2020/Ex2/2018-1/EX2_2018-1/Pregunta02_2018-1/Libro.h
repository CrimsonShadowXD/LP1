/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Libro.h
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 02:40 PM
 */
#include <fstream>
#include <cstring>
#include "Autor.h"
#include <list>
#include <iterator>
using namespace std;
#ifndef LIBRO_H
#define LIBRO_H
class Libro {
private:
    char* codigo;
    char* titulo;
    list<Autor> autores;
    double precio;
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
    
    void SetTitulo(const char* titulo);
    void GetTitulo(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    void SetAutor(const int dni, const char *nombre);
    void GetAutor(int n, int &dni, char*nombre);
    void EliminaAutores(void);
    
    void imprime(ofstream &);
    void operator++(void);

};
void operator>>(ifstream &,class Libro &);
void operator<<(ofstream &,  class Libro &);
#endif /* LIBRO_H */


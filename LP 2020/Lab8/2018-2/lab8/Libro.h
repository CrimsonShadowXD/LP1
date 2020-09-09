/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: crimson
 *
 * Created on July 8, 2020, 3:58 AM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Libro {
private:
    char *titulo;
    char *autor;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetAutor(const char* cad);
    void GetAutor(char*) const;
    void SetTitulo(const char* cad);
    void GetTitulo(char*) const;

    void operator=(const Libro&);
};

#endif /* LIBRO_H */


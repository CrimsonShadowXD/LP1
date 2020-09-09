/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Book100.h
 * Author: crimson
 *
 * Created on July 8, 2020, 4:00 AM
 */

#ifndef BOOK100_H
#define BOOK100_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Libro.h"

using namespace std;

class Book100:public Libro {
private:
    char *gen;
    int pag;
    char *editorial;
public:
    Book100();
    Book100(const Book100& orig);
    virtual ~Book100();
    void SetEditorial(const char* );
    void GetEditorial( char*) const;
    void SetPag(int pag);
    int GetPag() const;
    void SetGen(const char* );
    void GetGen( char*) const;
    
    void operator=(const Book100&);
};

ifstream &operator >> (ifstream &,Book100 &);
ofstream &operator << (ofstream &, const Book100 &);
    

#endif /* BOOK100_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Book.h
 * Author: crimson
 *
 * Created on July 8, 2020, 4:00 AM
 */

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Libro.h"

using namespace std;

class Book:public Libro {
private:
    int ano;
    char *pais;
    char *pag;
    char *arch;
    char *web;
public:
    Book();
    Book(const Book& orig);
    virtual ~Book();
    void SetWeb(const char*  );
    void GetWeb(char*) const;
    void SetArch(const char*  );
    void GetArch(char*) const;
    void SetPag(const char*  );
    void GetPag(char*) const;
    void SetPais(const char*  );
    void GetPais(char*) const;
    void SetAno(int ano);
    int GetAno() const;
    
    void operator=(const Book&);
};

ifstream &operator >> (ifstream &,Book &);
ofstream &operator << (ofstream &, const Book &);

#endif /* BOOK_H */


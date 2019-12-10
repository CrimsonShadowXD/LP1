/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paper.h
 * Author: Daniela
 *
 * Created on 22 de noviembre de 2017, 04:08 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#ifndef PAPER_H
#define PAPER_H
#include <fstream>
#include <iostream>
#include <list>
#include "Author.h"
using namespace std;
class Paper {
public:
    Paper();
    Paper(int , char*  , int );
    Paper(const Paper& orig);
    virtual ~Paper();
    void SetPublication_year(int publication_year);
    int GetPublication_year() const;
    void SetTitle(char* title);
    void GetTitle(char *) const;
    void SetId(int id);
    int GetId() const;
    void GetListaAuthor(char*);
    virtual void leerDatos(istream& arch);
    virtual void citar(ostream &)=0;

    bool operator < (const Paper& );
    bool operator > (const Paper&);
    bool operator == (const Paper&);
    void SetTipo(char tipo);
    char GetTipo() const;
    
private:
    int id;
    char tipo;
    char* title;
    int publication_year;
    list<Author> lstAuthors;
};

#endif /* PAPER_H */


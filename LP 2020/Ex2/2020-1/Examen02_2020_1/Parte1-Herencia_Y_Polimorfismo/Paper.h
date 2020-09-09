/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paper.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 08:12 AM
 */

#ifndef PAPER_H
#define PAPER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Paper {
private:
    int id,publication_year;
    char *title,*author_name;
public:
    Paper();
    Paper(const Paper& orig);
    Paper(const char*,const char*,int, int);
    virtual ~Paper();
    void SetAuthor_name(const char*  );
    void GetAuthor_name(char*) const;
    void SetTitle(const char*    );
    void GetTitle(char*) const;
    void SetPublication_year(int publication_year);
    int GetPublication_year() const;
    void SetId(int id);
    int GetId() const;
    
    virtual void leerDatos(ifstream&)=0; 
    virtual void citar(ofstream&)=0; 
};

#endif /* PAPER_H */


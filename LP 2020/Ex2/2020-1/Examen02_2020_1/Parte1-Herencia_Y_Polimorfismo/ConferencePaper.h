/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferencePaper.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 08:12 AM
 */

#ifndef CONFERENCEPAPER_H
#define CONFERENCEPAPER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Paper.h"
using namespace std;

class ConferencePaper : public Paper{
private:
    char *conference_name,*host_country;
public:
    ConferencePaper();
    ConferencePaper(const ConferencePaper& orig);
    ConferencePaper(const char*,const char*);
    virtual ~ConferencePaper();
    void setHost_country(const char*);
    void getHost_country(char*) const;
    void setConference_name(const char*  );
    void getConference_name(char*) const;
    
    void leerDatos(ifstream&); 
    void citar(ofstream&);
};

#endif /* CONFERENCEPAPER_H */


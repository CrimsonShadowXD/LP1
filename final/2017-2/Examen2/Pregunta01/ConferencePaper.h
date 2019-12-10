/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferencePaper.h
 * Author: Daniela
 *
 * Created on 22 de noviembre de 2017, 04:08 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#ifndef CONFERENCEPAPER_H
#define CONFERENCEPAPER_H

#include "Paper.h"
#include <iostream>
using namespace std;

class ConferencePaper: public Paper{
public:
    ConferencePaper();
    ConferencePaper(const ConferencePaper& orig);
    ConferencePaper(int , char* , int , int , char*  , int , char* );
    virtual ~ConferencePaper();
    void SetHost_country(char* host_country);
    void GetHost_country(char *) const;
    void SetEdition(int edition);
    int GetEdition() const;
    void SetConference_name(char* conference_name);
    void GetConference_name(char *) const;
    void leerDatos(istream& arch);
    void citar(ostream &);

private:
    char* conference_name;
    int edition;
    char * host_country;
};

#endif /* CONFERENCEPAPER_H */


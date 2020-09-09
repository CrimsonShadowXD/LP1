/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JournalPaper.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 08:12 AM
 */

#ifndef JOURNALPAPER_H
#define JOURNALPAPER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring> 
#include "Paper.h"
using namespace std;

class JournalPaper : public Paper{
private:
    char *journal_name;
    int volume;
public:
    JournalPaper();
    JournalPaper(const JournalPaper& orig);
    JournalPaper(const char*,int);
    virtual ~JournalPaper();
    
    void setVolume(int volume);
    int getVolume() const;
    void setJournal_name(const char*);
    void getJournal_name(  char*) const;
    
    void leerDatos(ifstream&); 
    void citar(ofstream&);
};

#endif /* JOURNALPAPER_H */


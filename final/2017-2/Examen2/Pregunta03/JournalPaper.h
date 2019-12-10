/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JournalPaper.h
 * Author: Daniela
 *
 * Created on 22 de noviembre de 2017, 04:09 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#ifndef JOURNALPAPER_H
#define JOURNALPAPER_H

#include "Paper.h"
#include <iostream>
using namespace std;

class JournalPaper: public Paper{
public:
    JournalPaper();
    JournalPaper(int , char* , int ,char* , int , int , char* );
    JournalPaper(const JournalPaper& orig);
    virtual ~JournalPaper();
    void SetPages(char* pages);
    void GetPages(char *) const;
    void SetIssue(int issue);
    int GetIssue() const;
    void SetVolume(int volume);
    int GetVolume() const;
    void SetJournal_name(char* journal_name);
    void GetJournal_name(char *) const;
    void leerDatos(istream& arch);
    void citar(ostream &);

private:
    char * journal_name;
    int volume;
    int issue;
    char* pages;
};

#endif /* JOURNALPAPER_H */


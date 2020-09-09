/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JournalPaper.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 08:12 AM
 */

#include "JournalPaper.h"

JournalPaper::JournalPaper() {
    journal_name=NULL;
    volume=-1;
}

JournalPaper::JournalPaper(const JournalPaper& orig) {
    journal_name=NULL;
    *this=orig;
}


JournalPaper::JournalPaper(const char*nom,int vol){ 
    setJournal_name(nom);
    setVolume(vol);
}

JournalPaper::~JournalPaper() {
    if (journal_name != NULL) delete journal_name;
}

void JournalPaper::setVolume(int volume) {
    this->volume = volume;
}

int JournalPaper::getVolume() const {
    return volume;
}

void JournalPaper::setJournal_name(const char* cad) {
    if (cad == NULL) return;
    if ( journal_name != NULL) delete journal_name;
    journal_name = new char[strlen(cad) + 1];
    strcpy(journal_name, cad); 
}

void JournalPaper::getJournal_name(char* cad) const {
    if (journal_name == NULL)
        return;
    strcpy(cad, journal_name); 
}

void JournalPaper::leerDatos(ifstream&in){ 
    char cad[250];
    int numero,ano,vol;
    in>>numero;
    SetId(numero);
    if(in.eof())return;
    in.get(); 
    in.getline(cad,250,';');
    SetAuthor_name(cad);
    in>>ano;
    in.get();
    SetPublication_year(ano); 
    in.getline(cad,250,';');
    SetTitle(cad);
    in.getline(cad,250,';');
    setJournal_name(cad); 
    in>>vol;
    in>>ws;
    setVolume(vol); 
}

void JournalPaper::citar(ofstream&out){ 
    char cad[250];
    GetAuthor_name(cad);
    out<<cad<<' ';
    out<<'('<<GetPublication_year()<<')'<<". ";
    GetTitle(cad);
    out<<cad<<". ";
    getJournal_name(cad);
    out<<cad<<", "; 
    out<<getVolume()<<'.'<<endl;
}
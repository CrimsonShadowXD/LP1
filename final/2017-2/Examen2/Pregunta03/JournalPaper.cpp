/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JournalPaper.cpp
 * Author: Daniela
 * 
 * Created on 22 de noviembre de 2017, 04:09 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz

#include "JournalPaper.h"
#include <iostream>
#include <cstring>
#include "Paper.h"
using namespace std;
JournalPaper::JournalPaper() {
    journal_name=NULL;
    pages=NULL;
}
JournalPaper::JournalPaper(int id, char* title, int pub,char* nombre, int volumen, int numero, char* paginas) :Paper(id,title,pub) {
    journal_name=NULL;
    pages=NULL;
    
    SetJournal_name(nombre);
    SetVolume(volumen);
    SetIssue(numero);
    SetPages(paginas);
    SetTipo('J');
};

JournalPaper::JournalPaper(const JournalPaper& orig) {
    journal_name=NULL;
    pages=NULL;
    
    SetId(orig.GetId());
    
    SetPublication_year(orig.GetPublication_year());
    SetVolume(orig.GetVolume());
    SetIssue(orig.GetIssue());
        
    char titulo[200],nombreJor[200],pag[200];
    orig.GetTitle(titulo);
    orig.GetJournal_name(nombreJor);
    orig.GetPages(pag);
    SetTitle(titulo);
    SetJournal_name(nombreJor);
    SetPages(pag);
  
    
}

JournalPaper::~JournalPaper() {
    if(journal_name) delete [] journal_name;
    if(pages) delete [] pages;
}

void JournalPaper::SetPages(char* c) {
    if(pages) delete pages;
    pages= new char [strlen(c)+1];
    strcpy(pages,c);
}

void JournalPaper::GetPages(char *c) const {
    strcpy(c,journal_name);
}

void JournalPaper::SetIssue(int issue) {
    this->issue = issue;
}

int JournalPaper::GetIssue() const {
    return issue;
}

void JournalPaper::SetVolume(int volume) {
    this->volume = volume;
}

int JournalPaper::GetVolume() const {
    return volume;
}

void JournalPaper::SetJournal_name(char* c) {
    if(journal_name) delete journal_name;
    journal_name= new char [strlen(c)+1];
    strcpy(journal_name,c);
}

void JournalPaper::GetJournal_name(char*c) const {
    strcpy(c,journal_name);
}
void JournalPaper::leerDatos(istream& arch) {
    int vol,num;
    char nomJor[200],pag[200];
    Paper::leerDatos(arch);
    
    arch.getline(nomJor,200,';');
    arch>>vol;
    arch.get();
    arch>>num;
    arch.get();
    arch.getline(pag,200);
    
    SetJournal_name(nomJor);
    SetVolume(vol);
    SetIssue(num);
    SetPages(pag);
}

void JournalPaper::citar(ostream& arch) {
    char titulo[200];

    GetTitle(titulo);
    char autores[500];
    GetListaAuthor(autores);

    arch<<autores<<" ("<<GetPublication_year()<<"). "<< titulo
            <<". "<<journal_name<<". "<<volume<<" ("<<issue<<"). "<<pages<<". "<<endl;
}

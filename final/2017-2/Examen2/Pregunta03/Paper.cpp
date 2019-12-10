/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paper.cpp
 * Author: Daniela
 * 
 * Created on 22 de noviembre de 2017, 04:08 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#include "Paper.h"
#include <iostream>
#include <cstring>
using namespace std;
Paper::Paper(){
    title=NULL;
}
Paper::Paper(int idPap, char* titulo, int pub) {
    title=NULL;
    SetId(idPap);
    SetTitle(titulo);
    
    SetPublication_year(pub);
}

Paper::Paper(const Paper& orig) {
    title=NULL;
    SetId(orig.id);
    
    SetPublication_year(orig.publication_year);
    SetTitle(orig.title);
}

Paper::~Paper() {
    if(title) delete [] title;
}

void Paper::SetPublication_year(int publication_year) {
    this->publication_year = publication_year;
}

int Paper::GetPublication_year() const {
    return publication_year;
}

void Paper::SetTitle(char* c) {
    if(title) delete title;
    title= new char [strlen(c)+1];
    strcpy(title,c);
}

void Paper::GetTitle(char* c) const {
    strcpy(c,title);
}

void Paper::SetId(int id) {
    this->id = id;
}

int Paper::GetId() const {
    return id;
}

void Paper::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Paper::GetTipo() const {
    return tipo;
}

void Paper::leerDatos(istream& arch) {
    int codPaper,pub,codAut;
    char titulo[1000];
    int numAut;
    char first[100],last[100];
    arch>>codPaper;
    arch.get();
    
    arch>>numAut;
    arch.get();
    
    for(int i=0;i<numAut;i++){
        arch>>codAut;
        arch.get(); 
        arch.getline(first,200,';');
        arch.getline(last,200,';');
        Author a ;
        a.SetId(codAut);
        a.SetFirst_name(first);
        a.SetLast_name(last);
        lstAuthors.push_back(a);
    }

    arch>>pub;
    arch.get();
    arch.getline(titulo,1000,';');
    
    SetId(codPaper);
    SetPublication_year(pub);
    SetTitle(titulo);
    
}

bool Paper::operator<(const Paper& p) {
    return GetId()<p.GetId();
}

bool Paper::operator==(const Paper& p) {
    return GetId()==p.GetId();
}



bool Paper::operator>(const Paper& p) {
    if(publication_year==p.publication_year) return strcmp(title,p.title)>0;
    return publication_year>p.publication_year;
}

void Paper::GetListaAuthor(char* c) {
    char buff[500]={0};
    char f[200],l[200];
    for(list<Author>::iterator it= lstAuthors.begin();it!=lstAuthors.end();it++){
        Author a= *it;
        a.GetFirst_name(f);
        a.GetLast_name(l);
        strcat(buff,l);
        strcat(buff,",");
        strcat(buff,f);
        strcat(buff,";");
    }
    int i=strlen(buff);
    buff[i-1]=0;
    strcpy(c,buff);
}

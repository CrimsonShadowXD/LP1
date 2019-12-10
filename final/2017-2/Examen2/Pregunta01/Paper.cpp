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
Paper::Paper(int idPap, char* titulo , int idAut, int pub) {
    title=NULL;
    SetId(idPap);
    SetTitle(titulo);
    SetId_author(idAut);
    SetPublication_year(pub);
}

Paper::Paper(const Paper& orig) {
    title=NULL;
    SetId(orig.id);
    SetId_author(orig.id_author);
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

void Paper::SetId_author(int id_author) {
    this->id_author = id_author;
}

int Paper::GetId_author() const {
    return id_author;
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
    int cod,pub,codAut;
    char titulo[200];
    arch>>cod;
    arch.get();
    arch>>codAut;
    arch.get();
    
    arch>>pub;
    arch.get();
    arch.getline(titulo,200,';');
    
    SetId(cod);
    SetId_author(codAut);
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


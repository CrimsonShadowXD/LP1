/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Book100.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 4:00 AM
 */

#include "Book100.h"

Book100::Book100() {
    gen=NULL;
    pag=-1;
    editorial=NULL;
}

Book100::Book100(const Book100& orig) {
}

Book100::~Book100() {
}

void Book100::SetEditorial(const char* cad) {
    if (cad==NULL) return;
    if(editorial!=NULL) delete editorial;
    editorial = new char[strlen(cad)+1];
    strcpy(editorial,cad);
}

void Book100::GetEditorial(char* cad) const {
    if(editorial==NULL)
        return;
    strcpy(cad,editorial);
}

void Book100::SetPag(int pag) {
    this->pag = pag;
}

int Book100::GetPag() const {
    return pag;
}

void Book100::SetGen(const char* cad) {
    if (cad==NULL) return;
    if(gen!=NULL) delete gen;
    gen = new char[strlen(cad)+1];
    strcpy(gen,cad);
}

void Book100::GetGen(char* cad) const {
    if(gen==NULL)
        return;
    strcpy(cad,gen);
}

void Book100::operator=(const Book100& nuevo){
    char cad[500];
    nuevo.GetAutor(cad);
    SetAutor(cad);
    SetPag(nuevo.GetPag());
    nuevo.GetEditorial(cad);
    SetEditorial(cad);
}

ifstream &operator >> (ifstream &in,Book100 &nuevo){
    
}

ofstream &operator << (ofstream &out, const Book100 &orig){
    
}
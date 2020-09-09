/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Book.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 4:00 AM
 */

#include "Book.h"

Book::Book() {
    ano=-1;
    pais=NULL;
    pag=NULL;
    arch=NULL;
    web=NULL;
}

Book::Book(const Book& orig) {
}

Book::~Book() {
}

void Book::SetWeb(const char* cad) {
    if (cad==NULL) return;
    if(web!=NULL) delete web;
    web = new char[strlen(cad)+1];
    strcpy(web,cad);
}

void Book::GetWeb(char* cad) const {
    if(web==NULL)
        return;
    strcpy(cad,web); 
}

void Book::SetArch(const char* cad) {
    if (cad==NULL) return;
    if(arch!=NULL) delete arch;
    arch = new char[strlen(cad)+1];
    strcpy(arch,cad);
}

void Book::GetArch(char* cad) const {
    if(arch==NULL)
        return;
    strcpy(cad,arch); 
}

void Book::SetPag(const char* cad) {
    if (cad==NULL) return;
    if(pag!=NULL) delete pag;
    pag = new char[strlen(cad)+1];
    strcpy(pag,cad);
}

void Book::GetPag(char* cad) const {
    if(pag==NULL)
        return;
    strcpy(cad,pag); 
}

void Book::SetPais(const char* cad) {
    if (cad==NULL) return;
    if(pais!=NULL) delete pais;
    pais = new char[strlen(cad)+1];
    strcpy(pais,cad);
}

void Book::GetPais(char* cad) const {
    if(pais==NULL)
        return;
    strcpy(cad,pais); 
}

void Book::SetAno(int ano) {
    this->ano = ano;
}

int Book::GetAno() const {
    return ano;
}

void Book::operator=(const Book& nuevo){
    ano=nuevo.ano;
    pais=nuevo.pais;
    pag=nuevo.pag;
    arch=nuevo.arch;
    web=nuevo.web;
}

ifstream &operator >> (ifstream &in,Book &nuevo){
    
}

ofstream &operator << (ofstream &out, const Book &orig){
    
}
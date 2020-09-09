/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paper.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 08:12 AM
 */

#include "Paper.h"

Paper::Paper() {
    title=NULL;
    author_name=NULL;
    id=-1;
    publication_year=-1; 
}

Paper::Paper(const Paper& orig) {
    title=NULL;
    author_name=NULL;
    *this=orig;
}

Paper::Paper(const char*nom,const char*titulo,int id, int ano){ 
    SetAuthor_name(nom);
    SetId(id);
    SetPublication_year(ano);
    SetTitle(titulo);
}

Paper::~Paper() {
    if (title != NULL) delete title;
    if (author_name != NULL) delete author_name;
}

void Paper::SetAuthor_name(const char* cad) {
    if (cad == NULL) return;
    if (author_name != NULL) delete author_name;
    author_name = new char[strlen(cad) + 1];
    strcpy(author_name, cad);
}

void Paper::GetAuthor_name(char* cad) const {
    if (author_name == NULL)
        return;
    strcpy(cad, author_name);
}

void Paper::SetTitle(const char* cad) {
    if (cad == NULL) return;
    if (title != NULL) delete title;
    title = new char[strlen(cad) + 1];
    strcpy(title, cad);
}

void Paper::GetTitle(char* cad) const {
    if (title == NULL)
        return;
    strcpy(cad, title);
}

void Paper::SetPublication_year(int publication_year) {
    this->publication_year = publication_year;
}

int Paper::GetPublication_year() const {
    return publication_year;
}

void Paper::SetId(int id) {
    this->id = id;
}

int Paper::GetId() const {
    return id;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 3:58 AM
 */

#include "Libro.h"

Libro::Libro() {
    titulo=NULL;
    autor=NULL;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetAutor(const char* cad) {
    if (cad==NULL) return;
    if(autor!=NULL) delete autor;
    autor = new char[strlen(cad)+1];
    strcpy(autor,cad);
}

void Libro::GetAutor(char* cad) const {
    if(autor==NULL)
        return;
    strcpy(cad,autor);
}

void Libro::SetTitulo(const char* cad) {
    if (cad==NULL) return;
    if(titulo!=NULL) delete titulo;
    titulo = new char[strlen(cad)+1];
    strcpy(titulo,cad);
}

void Libro::GetTitulo(char* cad) const {
    if(titulo==NULL)
        return;
    strcpy(cad,titulo);
}


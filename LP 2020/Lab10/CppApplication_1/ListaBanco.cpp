/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaBanco.cpp
 * Author: crimson
 * 
 * Created on July 15, 2020, 5:38 PM
 */

#include "ListaBanco.h"

ListaBanco::ListaBanco() {
    nom=NULL;
    tipo='&';
    cod=-1;
}

ListaBanco::ListaBanco(const ListaBanco& orig) {
    nom=NULL;
    *this=orig;
}

ListaBanco::~ListaBanco() {
}

void ListaBanco::SetCod(int cod) {
    this->cod = cod;
}

int ListaBanco::GetCod() const {
    return cod;
}

void ListaBanco::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void ListaBanco::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}

void ListaBanco::SetTipo(char tipo) {
    this->tipo = tipo;
}

char ListaBanco::GetTipo() const {
    return tipo;
}

void ListaBanco::operator=(const ListaBanco& l){
    char cad[150];
    l.GetNom(cad);
    SetNom(cad);
    SetCod(l.GetCod());
    SetTipo(l.GetTipo());
}

ofstream& operator<<(ofstream&out, ListaBanco&l){
    char cad[150];
    l.GetNom(cad);
    out<<cad<<' ';
    out<<l.GetCod()<<' ';
    out<<l.GetTipo()<<endl;
    return out;
}

void operator>>(ifstream&in, ListaBanco&l){
    //
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: crimson
 * 
 * Created on July 15, 2020, 4:49 PM
 */

#include "Profesor.h"

Profesor::Profesor() {
    dedicacion=NULL;
    categoria=NULL;
    nom=NULL;
}

Profesor::Profesor(const Profesor& orig) {
    dedicacion=NULL;
    categoria=NULL;
    nom=NULL;
    *this=orig;
}

Profesor::~Profesor() {
}

void Profesor::SetDedicacion(const char* cad) {
    if (cad == NULL) return;
    if (dedicacion != NULL) delete dedicacion;
    dedicacion = new char[strlen(cad) + 1];
    strcpy(dedicacion, cad);
}

void Profesor::GetDedicacion(char* cad) const {
    if (dedicacion == NULL)
        return;
    strcpy(cad, dedicacion);
}

void Profesor::SetCategoria(const char* cad) {
    if (cad == NULL) return;
    if (categoria != NULL) delete categoria;
    categoria = new char[strlen(cad) + 1];
    strcpy(categoria, cad);
}

void Profesor::GetCategoria(char* cad) const {
    if (categoria == NULL)
        return;
    strcpy(cad, categoria);
}

void Profesor::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void Profesor::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}

void Profesor::SetCod(int cod) {
    this->cod = cod;
}

int Profesor::GetCod() const {
    return cod;
}

void Profesor::operator=(const Profesor& p){
    char cad[150];
    p.GetCategoria(cad);
    SetCategoria(cad);
    p.GetDedicacion(cad);
    SetDedicacion(cad);
    p.GetNom(cad);
    SetNom(cad);
    SetCod(p.GetCod());
}

bool Profesor::operator>(const Profesor&p){
    char cad1[150],cad2[150];
    p.GetNom(cad2);
    GetNom(cad1);
    return (strcmp(cad1,cad2)>0);
}

bool Profesor::operator<(const Profesor&p){
    char cad1[150],cad2[150];
    p.GetNom(cad2);
    GetNom(cad1);
    return (strcmp(cad1,cad2)<0);
}

ofstream& operator<<(ofstream&out, Profesor&p){
    char cad[150];
    p.GetCategoria(cad);
    out<<cad<<' ';
    p.GetDedicacion(cad);
    out<<cad<<' ';
    p.GetNom(cad);
    out<<cad<<' ';
    out<<p.GetCod()<<endl;
    return out;
}

void operator>>(ifstream&in, Profesor&p){
    char cad[150];
    int cod,escala;
    in.getline(cad,150,',');p.SetNom(cad);
    in>>cod;p.SetCod(cod);
    in.get();
    in.getline(cad,150,',');
    in.getline(cad,150,',');p.SetCategoria(cad);
    in.getline(cad,150,',');p.SetDedicacion(cad);
    in.getline(cad,150);
}

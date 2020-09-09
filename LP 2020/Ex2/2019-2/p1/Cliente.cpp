/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: crimson
 * 
 * Created on July 14, 2020, 12:06 PM
 */

#include "Cliente.h"

Cliente::Cliente() {
    nom=NULL;
}

Cliente::~Cliente() {
}

void Cliente::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void Cliente::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}

void Cliente::SetTiempo(double tiempo) {
    this->tiempo = tiempo;
}

double Cliente::GetTiempo() const {
    return tiempo;
}

void Cliente::SetHini(int hini) {
    this->hini = hini;
}

int Cliente::GetHini() const {
    return hini;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator =(const Cliente&cli){
    char cad[150];
    cli.GetNom(cad);
    SetNom(cad);
    SetHini(cli.GetHini());
    SetDni(cli.GetDni());
    SetTiempo(cli.GetTiempo());
}

ofstream& operator<<(ofstream&out,Cliente&cli){
    char cad[150];
    cli.GetNom(cad);
    out<<cad<<' ';
    out<<cli.GetHini()<<' ';
    out<<cli.GetDni()<<' ';
    out<<cli.GetTiempo()<<endl;
    return out;
}

void operator>>(ifstream&in,Cliente&cli){
    char nomb[100];
    int iden,hLLeg,mLLeg,sLleg;
    double demora;
    
    in>>iden;
    if(in.eof())return;
    in.get();
    in.getline(nomb,100,',');
    in>>hLLeg;
    in.get();
    in>>mLLeg;
    in.get();
    in>>sLleg;
    in.get();
    in>>demora;
    in.get();
    
    cli.SetDni(iden);
    cli.SetHini(hLLeg*10000+mLLeg*100+sLleg);
    cli.SetNom(nomb);
    cli.SetTiempo(demora);
}

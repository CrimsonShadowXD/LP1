/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 3:54 PM
 */

#include "Intercambio.h"

Intercambio::Intercambio() {
    pais=NULL;
    idioma=NULL;
}

void Intercambio::setSemestres(int semestres) {
    this->semestres = semestres;
}

int Intercambio::getSemestres() const {
    return semestres;
}

void Intercambio::setIdioma(const char* cad) {
    if (cad == NULL) return;
    if (idioma != NULL) delete idioma;
    idioma = new char[strlen(cad) + 1];
    strcpy(idioma, cad); 
}

void Intercambio::getIdioma(char* cad) const {
    if (idioma == NULL)
        return;
    strcpy(cad, idioma); 
}

void Intercambio::setPais(const char* cad) {
    if (cad == NULL) return;
    if (pais != NULL) delete pais;
    pais = new char[strlen(cad) + 1];
    strcpy(pais, cad); 
}

void Intercambio::getPais(char* cad) const {
   if (pais == NULL)
        return;
    strcpy(cad, pais); 
}

Intercambio::Intercambio(const Intercambio& orig) {
    pais=NULL;
    idioma=NULL;
}

Intercambio::~Intercambio() {
}

void Intercambio::leer(ifstream&in){
    int cod,sem;
    char cad[150];
    in>>cod;
    if(in.eof())return;
    SetCodigo(cod);
    in.get();
    in.getline(cad,150,',');
    SetNombre(cad);
    in.getline(cad,150,',');
    setIdioma(cad);
    in.getline(cad,150,',');
    setPais(cad); 
    in>>sem;
    setSemestres(sem);
    in>>ws;
}

void Intercambio::imprimir(ofstream&out){
    char cad[150];
    out<<GetCodigo()<<' '; 
    GetNombre(cad);
    out<<cad<<' ';
    getIdioma(cad);
    out<<cad<<' '; 
    getPais(cad); 
    out<<cad<<' ';
    out<<getSemestres()<<endl;
    if(!notas.empty())imprimirNotas(out);
    else out<<"vacio"<<endl;
}

char Intercambio::getTipo(){
    return 'I';
}

void Intercambio::insertarNota(const CursoNotas&x){
    notas.push_back(x);
}

void Intercambio::imprimirNotas(ofstream&out){
    list <CursoNotas>::iterator it;
    for(it=notas.begin();it!=notas.end();it++){
        out<<*it<<endl;
    }
    out<<endl;
}
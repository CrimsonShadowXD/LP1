/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlIntercambio.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 5:29 AM
 */

#include "AlIntercambio.h"

AlIntercambio::AlIntercambio() {
    porigen=NULL;
    semestres=-1;
}

AlIntercambio::AlIntercambio(const AlIntercambio& orig) {
}

AlIntercambio::~AlIntercambio() {
}

void AlIntercambio::SetSemestres(int semestres) {
    this->semestres = semestres;
}

int AlIntercambio::GetSemestres() const {
    return semestres;
}

void AlIntercambio::SetPorigen(char* cad) {
    if (cad==NULL) return;
    if(porigen!=NULL) delete porigen;
    porigen = new char[strlen(cad)+1];
    strcpy(porigen,cad);
}

void AlIntercambio::GetPorigen(char* cad) const {
    if(porigen==NULL)
        return;
    strcpy(cad,porigen);
}

void AlIntercambio::leer(ifstream&in){
    int codigo; char buff[500]; int semestres=-1; int n=0;
   char *buffIdiomas[20], c;
    in>>codigo; in.get(); if (in.eof()) return;
    in.getline(buff,500,',');
    this->SetNombre(buff);
    cout<<codigo<<' '<<buff<<' ';
    in.getline(buff,500,','); //Leemos el pais.
    this->SetPorigen(buff);
    cout<<buff<<' ';
    //Leemos los idiomas que habla.
    while(1){
        c=in.get();
//        in>>semestres; 
        if (c>='0' && c<='9'){
            in.unget();
            break;
        } //Se detiene cuando hallamos los semestres.
        in.unget();
        in.getline(buff,500,',');
        cout<<buff<<endl;
//        buffIdiomas[n]=new char [strlen(buff)+1];
//        strcpy(buffIdiomas[n],buff);
        n++;           
    }
    in>>semestres;
    cout<<semestres<<endl;
//    char **idiomas = new char* [n+1];
//    for(int i=0;i<n;i++) idiomas[i]=buffIdiomas[i];
//    idiomas[n]=nullptr;
//    this->SetIdiomas(idiomas); //Setter de los idiomas.
    this->SetSemestres(semestres);
}

void AlIntercambio::imprimir(ofstream&out){
    char cad[200];
    out<<"Codigo de Alumno: "<<GetCodigo()<<endl;
    GetNombre(cad);
    out<<"Alumno de Intercambio\nNombre del alumno:"<<cad<<endl;
    GetPorigen(cad);
    out<<"Pais: "<<cad<<endl;
    out<<"Idiomas: ";  
//    for(int i=0; this->idiomas[i];i++){
//        out<<idiomas[i]<<' '; 
//        if (idiomas[i+1]) out<<"- ";               
//    } 
    out<<endl;
    out<<"Permanecerá "<<GetSemestres()<<" semestres"<<endl;
}

void AlIntercambio::SetIdiomas(char** idiomas) {
    this->idiomas = idiomas;
}

char** AlIntercambio::GetIdiomas() const {
    return idiomas;
}

char AlIntercambio::getTipo(){
    return 'I';
}
    
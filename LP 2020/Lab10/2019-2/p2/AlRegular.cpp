/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlRegular.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 5:28 AM
 */

#include "AlRegular.h"

AlRegular::AlRegular() {
    espec=NULL;
    facul=NULL;
}

AlRegular::AlRegular(const AlRegular& orig) {
}

AlRegular::~AlRegular() {
}

void AlRegular::SetFacul(char* cad) {
    if (cad==NULL) return;
    if(facul!=NULL) delete facul;
    facul = new char[strlen(cad)+1];
    strcpy(facul,cad);
}

void AlRegular::GetFacul(char* cad) const {
    if(facul==NULL)
        return;
    strcpy(cad,facul);
}

void AlRegular::SetEspec(char* cad) {
    if (cad==NULL) return;
    if(espec!=NULL) delete espec;
    espec = new char[strlen(cad)+1];
    strcpy(espec,cad);
}

void AlRegular::GetEspec(char* cad) const {
    if(espec==NULL)
        return;
    strcpy(cad,espec);
}

void AlRegular::leer(ifstream&in){
    int codigo; char buff[500];
    in>>codigo; cout<<codigo<<' ';
    in.get(); 
    if (in.eof()) return;
    
    in.getline(buff,500,','); cout<<buff<<' ';
    this->SetNombre(buff);
    in.getline(buff,500,','); cout<<buff<<' ';
    this->SetEspec(buff);
    in.getline(buff,500); cout<<buff<<endl;
    this->SetFacul(buff); 
}

void AlRegular::imprimir(ofstream&out){
    char cad[200];
    out<<"Codigo de Alumno: "<<GetCodigo()<<endl;
    GetNombre(cad);
    out<<"Alumno Regular\nNombre del alumno:"<<cad<<endl;
    GetEspec(cad);
    out<<"Especialidad: "<<cad<<endl;
    GetFacul(cad);
    out<<"Facultad"<<cad<<endl;
}

char AlRegular::getTipo(){
    return 'R';
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nacional.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 3:54 PM
 */

#include "Nacional.h"

Nacional::Nacional() {
    especialidad=NULL;
    facultad=NULL;
}

void Nacional::setFacultad(const char* cad) {
    if (cad == NULL) return;
    if (facultad != NULL) delete facultad;
    facultad = new char[strlen(cad) + 1];
    strcpy(facultad, cad); 
}

void Nacional::getFacultad(char* cad) const {
    if (facultad == NULL)
        return;
    strcpy(cad, facultad);
}

void Nacional::setEspecialidad(const char* cad) {
    if (cad == NULL) return;
    if (especialidad != NULL) delete especialidad;
    especialidad = new char[strlen(cad) + 1];
    strcpy(especialidad, cad); 
}

void Nacional::getEspecialidad(char* cad) const {
    if (especialidad == NULL)
        return;
    strcpy(cad, especialidad); 
}

Nacional::Nacional(const Nacional& orig) {
    especialidad=NULL;
    facultad=NULL;
}

Nacional::~Nacional() {
}

void Nacional::leer(ifstream&in){
    int cod;
    char cad[150];
    in>>cod;
    if(in.eof())return;
    SetCodigo(cod);
    in.get();
    in.getline(cad,150,',');
    SetNombre(cad);
    in.getline(cad,150,',');
    setEspecialidad(cad);
    in.getline(cad,150);
    setFacultad(cad);    
}

void Nacional::imprimir(ofstream&out){
    char cad[150];
    out<<GetCodigo()<<' '; 
    GetNombre(cad); 
    out<<cad<<' ';
    getEspecialidad(cad); 
    out<<cad<<' ';
    getFacultad(cad);  
    out<<cad<<endl;
    if(!notas.empty())imprimirNotas(out);
    else out<<"vacio"<<endl;
}

char Nacional::getTipo(){
    return 'R';
}

void Nacional::insertarNota(const CursoNotas&x){
    notas.push_back(x);
}

void Nacional::imprimirNotas(ofstream&out){
    list <CursoNotas>::iterator it;
    for(it=notas.begin();it!=notas.end();it++){
        out<<*it<<endl;
    }
    out<<endl;
}

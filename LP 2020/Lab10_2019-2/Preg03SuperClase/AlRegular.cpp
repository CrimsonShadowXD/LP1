
/* 
 * File:   AlRegular.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 6 de julio de 2020, 18:24
 */

#include "AlRegular.h"
#include <cstring>
#include <fstream>

using namespace std;

AlRegular::AlRegular() {
    facultad=nullptr;
    especialidad=nullptr;
}


AlRegular::~AlRegular() {
    if (facultad) delete [] facultad;
    if (especialidad) delete[] especialidad;
}

void AlRegular::SetFacultad(char* facultad) {
    this->facultad = new char [strlen(facultad)+1];
    strcpy(this->facultad,facultad);
}

char* AlRegular::GetFacultad() const {
        char *salida = new char [strlen(this->facultad)+1];
    strcpy(salida,this->facultad);
    return salida;
}

void AlRegular::SetEspecialidad(char* especialidad) {
       this->especialidad = new char [strlen(especialidad)+1];
    strcpy(this->especialidad,especialidad);
}

char* AlRegular::GetEspecialidad() const {
        char *salida = new char [strlen(this->especialidad)+1];
    strcpy(salida,this->especialidad);
    return salida;
}

void AlRegular::imprimir(ofstream &out){
    out<<"Codigo de Alumno: "<<this->GetCodigo()<<endl;
    out<<"Alumno Regular\nNombre del alumno:"<<GetNombre()<<endl;
    out<<"Especialidad: "<<GetEspecialidad()<<endl;
    out<<"Facultad: "<<GetFacultad()<<endl;
}

void AlRegular::leer(ifstream &in){
    int codigo; char buff[500];
    in>>codigo; in.get(); if (in.eof()) return;
    this->SetCodigo(codigo);
    in.getline(buff,500,',');
    this->SetNombre(buff);
    in.getline(buff,500,',');
    this->SetEspecialidad(buff);
    in.getline(buff,500);
    this->SetFacultad(buff);  
    
    
}

char AlRegular::getTipo(){
    return 'R';
}


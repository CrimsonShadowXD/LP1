/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regular.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 09:37 PM
 */

#include <fstream>
#include <cstring>
#include "Regular.h"

using namespace std;

Regular::Regular() {
    especialidad = NULL;
    facultad = NULL;
}

Regular::~Regular() {
}
    
    void Regular::setEspecialidad(char* entrada){
        especialidad = new char [strlen(entrada)+1];
        strcpy(especialidad,entrada);
    }
    void Regular::setFacultad(char* entrada){
        facultad = new char [strlen(entrada)+1];
        strcpy(facultad,entrada);        
    }
    
    char* Regular::getEspecialidad(){
        char *aux;
        aux = new char [strlen(especialidad)+1];
        strcpy(aux,especialidad);
        return aux;
    }
    char* Regular::getFacultad(){
        char *aux;
        aux = new char [strlen(facultad)+1];
        strcpy(aux,facultad);
        return aux;
    }
    
    char Regular::getTipo() {return 'R';}
    
    void Regular::imprimir(ofstream &out){
        out<<"Codigo de Alumno: "<<this->getCodigo()<<endl;
        out<<"Alumno Regular"<<endl;
        out<<"Nombre de Alumno: "<<this->getNombre()<<endl;        
        out<<"Especialidad: "<<getEspecialidad()<<endl;
        out<<"Facultad: "<<getFacultad()<<endl;
    }
    void Regular::leer(ifstream &in){
        Alumno::leer(in);
        char buff[200];
        in.getline(buff,200,',');
        setEspecialidad(buff);
        in.getline(buff,200);
        setFacultad(buff);
    }

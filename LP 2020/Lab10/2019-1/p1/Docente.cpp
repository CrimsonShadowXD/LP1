/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 6:56 PM
 */

#include "Docente.h"

Docente::Docente() {
    categoria=NULL;
    dedicacion=NULL;
    seccion=NULL;
    grado=NULL;
    sueldo=-0.1;
}

Docente::Docente(const Docente& orig) {
}

Docente::~Docente() {
}

void Docente::setSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Docente::getSueldo() const {
    return sueldo;
}

void Docente::setGrado(const char* cad) {
    if (cad==NULL) return;
    if(grado!=NULL) delete grado;
    grado = new char[strlen(cad)+1];
    strcpy(grado,cad); 
}

void Docente::getGrado(char* cad) const {
    if(grado==NULL)
        return;
    strcpy(cad,grado); 
}

void Docente::setSeccion(const char* cad) {
    if (cad==NULL) return;
    if(seccion!=NULL) delete seccion;
    seccion = new char[strlen(cad)+1];
    strcpy(seccion,cad); 
}

void Docente::getSeccion(char* cad) const {
    if(seccion==NULL)
        return;
    strcpy(cad,seccion); 
}

void Docente::setDedicacion(const char* cad) {
    if (cad==NULL) return;
    if(dedicacion!=NULL) delete dedicacion;
    dedicacion = new char[strlen(cad)+1];
    strcpy(dedicacion,cad); 
}

void Docente::getDedicacion(char* cad) const {
    if(dedicacion==NULL)
        return;
    strcpy(cad,dedicacion); 
}

void Docente::setCategoria(const char* cad) {
    if (cad==NULL) return;
    if(categoria!=NULL) delete categoria;
    categoria = new char[strlen(cad)+1];
    strcpy(categoria,cad);
}

void Docente::getCategoria(char* cad) const {
    if(categoria==NULL)
        return;
    strcpy(cad,categoria); 
}

void Docente::leer(ifstream&in){

}

void Docente::imprimir(ofstream&out){
    out<<setw(50)<<"Miembro docente"<<endl;
    for(int i=0;i<150;i++)out<<'=';out<<endl;
    char cad[150];
    out<<"Codigo: "<<getCodigo()<<endl;
    getNombre(cad);
    out<<"Nombre del profesor: "<<cad<<endl;
    getDistrito(cad);
    out<<"Distrito: "<<cad<<endl;
    getCategoria(cad);
    out<<"Categoria: "<<cad<<endl;
    getDedicacion(cad);
    out<<"Dedicacion: "<<cad<<endl;
    getSeccion(cad);
    out<<"Seccion: "<<cad<<endl;
    getGrado(cad);
    out<<"Grado academico: "<<cad<<endl;
    out<<"Sueldo: "<<getSueldo()<<endl;
}

void Docente::getTipo(){

}

void Docente::modificar(float valor){
    double aux;
    aux=getSueldo();
    cout<<0.45*valor<<endl;
    setSueldo(aux*(1+0.45*valor));
}




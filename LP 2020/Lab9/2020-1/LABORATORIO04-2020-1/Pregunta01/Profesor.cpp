/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:03 AM
 */

#include "Profesor.h"

Profesor::Profesor() {
    categoria=NULL;
    dedicacion=NULL;
    seccion=NULL;
    grado=NULL;
}

Profesor::Profesor(const Profesor& orig) {
}

Profesor::~Profesor() {
    if (categoria != NULL) delete categoria;
    if (dedicacion != NULL) delete dedicacion;
    if (seccion != NULL) delete seccion;
    if (grado != NULL) delete grado;
}

void Profesor::SetGrado(const char* cad) {
    if (cad == NULL) return;
    if (grado != NULL) delete grado;
    grado = new char[strlen(cad) + 1];
    strcpy(grado, cad);
}

void Profesor::GetGrado(char* cad) const {
    if (grado == NULL)
        return;
    strcpy(cad, grado);
}

void Profesor::SetSeccion(const char* cad) {
    if (cad == NULL) return;
    if (seccion != NULL) delete seccion;
    seccion = new char[strlen(cad) + 1];
    strcpy(seccion, cad);
}

void Profesor::GetSeccion(char* cad) const {
    if (seccion == NULL)
        return;
    strcpy(cad, seccion);
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

void Profesor::leer(ifstream&in){
    char cad[150];
    int escala,cod;
    double creditaje,aprob;
    in.getline(cad,150,','); SetNombre(cad);
    in>>cod; SetCodigo(cod);
    in.get();
    in.getline(cad,150,','); SetDistrito(cad);
    in.getline(cad,150,','); SetCategoria(cad);
    in.getline(cad,150,','); SetDedicacion(cad);
    in.getline(cad,150,','); SetSeccion(cad);
    in.getline(cad,150); SetGrado(cad);
    in>>ws;
}

void Profesor::imprimir(ofstream&out){
    char cad[150];
    out<<"Codigo: "<<GetCodigo()<<endl;
    GetNombre(cad);
    out<<"Nombre del profesor: "<<cad<<endl;
    GetDistrito(cad);
    out<<"Distrito: "<<cad<<endl;
    GetCategoria(cad);
    out<<"Categoria: "<<cad<<endl;
    GetDedicacion(cad);
    out<<"Dedicacion: "<<cad<<endl;
    GetSeccion(cad);
    out<<"Seccion: "<<cad<<endl;
    GetGrado(cad);
    out<<"Grado academico: "<<cad<<endl;
    out<<"=========================="<<endl;
}

int Profesor::getPrio(){
    char cad[10];
    GetDedicacion(cad);
    if(strcmp(cad,"TC")==0)
        return 1;
    else if(strcmp(cad,"TP")==0)
        return 2;
    else if(strcmp(cad,"TPA")==0)
        return 3;
    return -1;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrativo.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 6:57 PM
 */

#include "Administrativo.h"

Administrativo::Administrativo() {
    puesto=NULL;
    gradoDeInstruccion=NULL;
    aDeServ=-1;
    sueldo=-0.1;
}

Administrativo::Administrativo(const Administrativo& orig) {
}

Administrativo::~Administrativo() {
}

void Administrativo::setSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Administrativo::getSueldo() const {
    return sueldo;
}

void Administrativo::setADeServ(int aDeServ) {
    this->aDeServ = aDeServ;
}

int Administrativo::getADeServ() const {
    return aDeServ;
}

void Administrativo::setGradoDeInstruccion(const char* cad) {
    if (cad==NULL) return;
    if(gradoDeInstruccion!=NULL) delete gradoDeInstruccion;
    gradoDeInstruccion = new char[strlen(cad)+1];
    strcpy(gradoDeInstruccion,cad);
}

void Administrativo::getGradoDeInstruccion(char* cad) const {
    if(gradoDeInstruccion==NULL)
        return;
    strcpy(cad,gradoDeInstruccion);
}

void Administrativo::setPuesto(const char* cad) {
    if (cad==NULL) return;
    if(puesto!=NULL) delete puesto;
    puesto = new char[strlen(cad)+1];
    strcpy(puesto,cad);
}

void Administrativo::getPuesto(char* cad) const {
    if(puesto==NULL)
        return;
    strcpy(cad,puesto);
}

void Administrativo::leer(ifstream&in){

}

void Administrativo::imprimir(ofstream&out){
    out<<setw(50)<<"Miembro administrativo"<<endl;
    for(int i=0;i<150;i++)out<<'=';out<<endl;
    char cad[150];
    out<<"Codigo: "<<getCodigo()<<endl;
    getNombre(cad);
    out<<"Nombre: "<<cad<<endl;
    getDistrito(cad);
    out<<"Distrito: "<<cad<<endl;
    getPuesto(cad);
    out<<"Puesto: "<<cad<<endl;
    getGradoDeInstruccion(cad);
    out<<"Grado de Instruccion: "<<cad<<endl;
    out<<"Años de servicio: "<<getADeServ()<<endl;
    out<<"Sueldo: "<<getSueldo()<<endl;
    
}

void Administrativo::getTipo(){

}

void Administrativo::modificar(float valor){
    double aux;
    aux=getSueldo();
    cout<<valor<<endl;
    setSueldo(aux*(1+valor));
}
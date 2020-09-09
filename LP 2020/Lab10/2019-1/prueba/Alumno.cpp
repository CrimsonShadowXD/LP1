/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 6:56 PM
 */

#include "Alumno.h"

Alumno::Alumno() {
    especalidad=NULL;
    facultad=NULL;
    escalaDePago=-1;
    valorDelCredito=-0.1;
    creditosAprobados=-0.1;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

void Alumno::setCreditosAprobados(double creditosAprobados) {
    this->creditosAprobados = creditosAprobados;
}

double Alumno::getCreditosAprobados() const {
    return creditosAprobados;
}

void Alumno::setValorDelCredito(double valorDelCredito) {
    this->valorDelCredito = valorDelCredito;
}

double Alumno::getValorDelCredito() const {
    return valorDelCredito;
}

void Alumno::setEscalaDePago(int escalaDePago) {
    this->escalaDePago = escalaDePago;
}

int Alumno::getEscalaDePago() const {
    return escalaDePago;
}

void Alumno::setFacultad(const char* cad) {
    if (cad==NULL) return;
    if(facultad!=NULL) delete facultad;
    facultad = new char[strlen(cad)+1];
    strcpy(facultad,cad);
}

void Alumno::getFacultad(char* cad) const {
    if(facultad==NULL)
        return;
    strcpy(cad,facultad);
}

void Alumno::setEspecalidad(const char* cad) {
    if (cad==NULL) return;
    if(especalidad!=NULL) delete especalidad;
    especalidad = new char[strlen(cad)+1];
    strcpy(especalidad,cad); 
}

void Alumno::getEspecalidad(char* cad) const {
    if(especalidad==NULL)
        return;
    strcpy(cad,especalidad);
}

void Alumno::leer(ifstream&in){
    char cad[150];
    int escala,cod;
    double creditaje,aprob;
    in.getline(cad,150,','); setNombre(cad);
    in>>cod; setCodigo(cod);
    in.get();
    in.getline(cad,150,','); setDistrito(cad);
    in.getline(cad,150,','); setEspecalidad(cad);
    in.getline(cad,150,','); setFacultad(cad);
    in>>escala; setEscalaDePago(escala);
    in.get();
    in>>creditaje; setValorDelCredito(creditaje);
    in.get();
    in>>aprob; setCreditosAprobados(aprob);
    in>>ws;
}

void Alumno::imprimir(ofstream&out){
    out<<setw(50)<<"Miembro alumno"<<endl;
    for(int i=0;i<150;i++)out<<'=';out<<endl;
    char cad[150];
    out<<"Codigo: "<<getCodigo()<<endl;
    getNombre(cad);
    out<<"Nombre del alumno: "<<cad<<endl;
    getDistrito(cad);
    out<<"Distrito: "<<cad<<endl;
    getEspecalidad(cad);
    out<<"Especialidad: "<<cad<<endl;
    getFacultad(cad);
    out<<"Facultad: "<<cad<<endl;
    out<<"Escala de pago: "<<getEscalaDePago()<<endl;
    out<<"Valor del credito: "<<getValorDelCredito()<<endl;
    out<<"Creditos aprobados: "<<getCreditosAprobados()<<endl;
}

void Alumno::getTipo(){

}

void Alumno::modificar(float valor){
    double aux;
    float x;
    int esc=getEscalaDePago();
    x=0.15*valor;
    for(int i=0;i<esc;i++){
        x+=0.05;
    }
    cout<<x<<endl;
    aux=getValorDelCredito();
    setValorDelCredito(aux*(1+x));
}

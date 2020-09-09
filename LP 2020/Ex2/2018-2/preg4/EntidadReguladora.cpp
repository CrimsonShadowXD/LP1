/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntidadReguladora.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 8:17 AM
 */

#include "EntidadReguladora.h"

EntidadReguladora::EntidadReguladora() {
}

EntidadReguladora::EntidadReguladora(const EntidadReguladora& orig) {
}

EntidadReguladora::~EntidadReguladora() {
}

void EntidadReguladora::cargarCond(){
    ifstream archIn("Conductores.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }   
    conductores.cargar(archIn);
}

void EntidadReguladora::cargarInfr(){
    ifstream archIn("Infracciones.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    } 
    infracciones.crear(archIn);
}

void EntidadReguladora::impPersonaMonto(ofstream&out,int dni){
    int *aux;
    double monto=0;
    aux=conductores.retornarTodasInfracciones(dni);
    if(aux!=NULL){
        for(int i=0;aux[i]!=-1;i++){
            monto+=infracciones.buscarMonto(aux[i]);
        }
    }
    conductores.ImprMulta(out,dni,monto);
}

void EntidadReguladora::imprimirMontos(){
    ofstream out("reporte.txt", ios::in);
    if (!out) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    out<<setw(30)<<"Entidad Reguladora de Transito"<<endl;
    int dni;
    impPersonaMonto(out,dni);
}
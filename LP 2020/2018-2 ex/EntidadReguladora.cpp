/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntidadReguladora.cpp
 * Author: crimson
 * 
 * Created on July 6, 2020, 12:19 AM
 */

#include "EntidadReguladora.h"

EntidadReguladora::EntidadReguladora() {
}

EntidadReguladora::EntidadReguladora(const EntidadReguladora& orig) {
}

EntidadReguladora::~EntidadReguladora() {
}

void EntidadReguladora::ProcesarDatos(){
    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cerr<<"error";
        exit(1);
    }
    ifstream arch2("Registro_de_Faltas.csv",ios::in);
    if(!arch2){
        cerr<<"error";
        exit(1);
    }
    ifstream arch3("Infracciones.csv",ios::in);
    if(!arch3){
        cerr<<"error";
        exit(1);
    }
    ofstream out("reporte4.txt",ios::out);
    ListaConductores cond;
    cond.crear(arch);
    cond.cargarinfracciones(arch2);
    ListaDoble<Infracciones> infr;
    infr.leer(arch3);
    cond.Calc_Impr_Montos(out,infr);
}
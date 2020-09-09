/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mov_Tab.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 10:22 PM
 */

#include "Mov_Tab.h"

Mov_Tab::Mov_Tab() {
}

Mov_Tab::Mov_Tab(const Mov_Tab& orig) {
}

Mov_Tab::~Mov_Tab() {
}

void Mov_Tab::cargaymover(){
    ifstream archf("Fichas.txt",ios::in);
    ifstream archm("Movimientos.txt",ios::in);
    ofstream archr("Reporte.txt",ios::out);
    tabla.leerFichas(archf);
    tabla.imprimeDatos(archr);
    archr<<"-----------"<<endl;
    tabla.leerMovimientos(archm);
    tabla.imprimeDatos(archr);
    
}
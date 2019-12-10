/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorPublicaciones.cpp
 * Author: alulab14
 * 
 * Created on 5 de diciembre de 2017, 09:08 AM
 */
//20150008 Daniela Cisneros
#include "GestorPublicaciones.h"
#include "ConferencePaper.h"
#include "JournalPaper.h"
#include "Paper.h"
GestorPublicaciones::GestorPublicaciones() {
    
}

GestorPublicaciones::GestorPublicaciones(const GestorPublicaciones& orig) {
}

GestorPublicaciones::~GestorPublicaciones() {
    lstPapers.eliminar();
}

void GestorPublicaciones::leerPapers(const char* nomArch) {
    ifstream arch (nomArch,ios::in);
    if(!arch){
        cerr<<"Error en la apertura"<<endl;
//        exit(1);
    }
    char tipo;
    while(1){
        Paper *p;
        tipo=arch.get();
        if(arch.eof()) break;
        if(tipo=='C') p= new ConferencePaper;
        else p= new JournalPaper;
        arch.get();
        p->leerDatos(arch);
        lstPapers.insertar(p);
    }

}

void GestorPublicaciones::imprimirReporte(const char* nomArch) {
    ofstream arch (nomArch,ios::out);
    if(!arch){
        cerr<<"Error en la apertura"<<endl;
//        exit(1);
    }
    lstPapers.imprimir(arch);
}

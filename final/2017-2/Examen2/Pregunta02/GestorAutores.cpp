/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorAutores.cpp
 * Author: alulab14
 * 
 * Created on 5 de diciembre de 2017, 08:12 AM
 */
//20150008 Daniela Cisneros
#include "GestorAutores.h"
#include "ConferencePaper.h"
#include "JournalPaper.h"

GestorAutores::GestorAutores() {
}

GestorAutores::GestorAutores(const GestorAutores& orig) {
}

GestorAutores::~GestorAutores() {
    
}

void GestorAutores::leerAuthors(const char* nomArch) {
    ifstream arch (nomArch,ios::in);
    if(!arch){
        cerr<<"Error en la apertura"<<endl;
//        exit(1);
    }
    while(1){
        Author a;
        arch>>a;
        if(arch.eof()) break;
//        cout<<a;
        lstAuthors.insertar(a);
    }
}

void GestorAutores::leerPapers(const char* nomArch) {
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
        insertarPaper(p->GetId_author(), p);
    }
}

void GestorAutores::imprimirReporte(const char* nomArch) {
    ofstream arch (nomArch,ios::out);
    if(!arch){
        cerr<<"Error en la apertura"<<endl;
//        exit(1);
    }
    lstAuthors.imprimir(arch);
}

void GestorAutores::insertarPaper(int cod, Paper * p) {
    lstAuthors.insertarPaper(cod,p);
}

void GestorAutores::eliminarLista() {
    lstAuthors.eliminar();
}

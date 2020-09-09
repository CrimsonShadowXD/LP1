/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Superclase.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:07 AM
 */

#include "Superclase.h"

Superclase::Superclase() {
}

Superclase::Superclase(const Superclase& orig) {
}

Superclase::~Superclase() {
}

void Superclase::leer(int &cant){
    ifstream in("Papers.csv", ios::in);
    if (!in) {
        cout << "No se puede abrir Papers" << endl;
        exit(1);
    }
    while(1){
        char T;
        in>>T;
        if(cant>=100)break;
        if (in.eof())break;
        in.get();
        if (T == 'C')
            lstPapers[cant] = new ConferencePaper;
        else if (T == 'J')
            lstPapers[cant] = new JournalPaper; 
        lstPapers[cant]->leerDatos(in);
        cant++;
    }
}

void Superclase::citar(int cant){
    ofstream out("citasLinux.txt", ios::out);
    if (!out) {
        cout << "No se puede abrir citas.txt" << endl;
        exit(1);
    } 
    for(int i=0;i<cant;i++)
        lstPapers[i]->citar(out);
}

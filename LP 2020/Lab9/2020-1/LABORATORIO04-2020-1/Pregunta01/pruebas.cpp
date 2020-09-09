/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pruebas.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:54 AM
 */

#include "pruebas.h"
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
void pruebas(){
    ifstream in("Miembros.csv",ios::in);
    if(!in){
        cout << "No se puede abrir Miembros.csv";
        exit(1);
    }
    ofstream out("ReportePrueba.txt",ios::out);
    if(!out){
        cout << "No se puede abrir";
        exit(1);
    }
    Persona *entrada;
    while (1) {
        char T;
        in>>T;
        if (in.eof())return;
        in.get();
        if (T == 'A')
            entrada = new Alumno;
        else if (T == 'P')
            entrada = new Profesor;
        entrada->leer(in);
        entrada->imprimir(out);
    }
}
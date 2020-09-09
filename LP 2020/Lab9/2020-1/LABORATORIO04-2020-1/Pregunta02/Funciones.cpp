/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 09:02 AM
 */

#include "Funciones.h"
#include "ListaPersonas.h"

void procesar(){
    ifstream arch("Miembros.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir Miembros.csv";
        exit(1);
    }
    ListaPersonas prueba;
    prueba.crear(arch);
    
    ofstream archi("ReporteFinal.txt",ios::out);
    if(!archi){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba.imp(archi);
}
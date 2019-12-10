/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 09:47 AM
 */
//20150008 Daniela Cisneros
#include <cstdlib>
#include "ColaPrioridad.h"
#include "ParEnteros.h"
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    ColaPrioridad<ParEnteros> cola;
    
    ifstream arch("Pares.txt",ios::in);
    if(!arch){
        cerr<<"Error de apertura"<<endl;
        exit(1);
    }
    ofstream archR("Reporte.txt",ios::out);
    if(!archR){
        cerr<<"Error de apertura"<<endl;
        exit(1);
    }
    int p,s;
    while(1){
        ParEnteros par;
        arch>>p;
        if(arch.eof()) break;
        arch>>s;
        par.SetPrimer(p);
        par.SetSegundo(s);
        cola.Arribo(par);
    }
    cola.Listado(archR);
    
    ParEnteros par;
    cola.Atencion(par);
    archR<<endl<<"Prueba de Atencion: "<<endl;
    archR<<par<<endl;
    
    cola.Listado(archR);
    
    return 0;
}


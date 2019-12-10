/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 10:03 AM
 */
//20150008 Daniela Cisneros

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "ColaPrioridad.h"
#include "Author.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ColaPrioridad<Author> cola;
    ifstream arch ("AuthorsPQ.csv",ios::in);
    if(!arch){
        cerr<<"Error en la apertura"<<endl;
        exit(1);
    }
    ofstream archR("Reporte.txt",ios::out);
    if(!archR){
        cerr<<"Error en la apertura"<<endl;
        exit(1);
    }
    while(1){
        Author a;
        arch>>a;
        if(arch.eof()) break;
        cola.Arribo(a);
    }
    cola.Listado(archR);
    
    Author a;
    cola.Atencion(a);
    archR<<endl<<"PRUEBA DE ATENCION: "<<endl;
    archR<<a<<endl;
    
    cola.Listado(archR);
    return 0;
}


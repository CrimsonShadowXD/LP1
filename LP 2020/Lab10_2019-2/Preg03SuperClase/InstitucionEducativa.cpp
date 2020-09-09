
/* 
 * File:   InstitucionEducativa.cpp
 * Author: Rodrigo Agama
 * 
 * Created on 6 de julio de 2020, 20:17
 */

#include "InstitucionEducativa.h"
#include <fstream>
#include <iostream>

using namespace std;

InstitucionEducativa::InstitucionEducativa() {
}


InstitucionEducativa::~InstitucionEducativa() {
}

void InstitucionEducativa::leerAlumnos(){
    ifstream in("Alumnos.csv",ios::in);
        if (!in){
            cout<<"Error creando el archivo de Alumnos. "<<endl; exit(1);
            
        }
    lista.leerLista(in);
    
}
    void InstitucionEducativa::leerCursos(){
        ifstream in("Cursos.csv",ios::in);
        if (!in){
            cout<<"Error creando el archivo de cursos. "<<endl; exit(1);
        }
        lista.leerNotas(in);
    }
    void InstitucionEducativa::imprimirReporte(){
        ofstream out("ReporteFinal.txt",ios::out);
        if (!out){
            cout<<"Error creando el archivo de reporte final. "<<endl; exit(1);            
        }
        lista.imprimirLista(out);
    }


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matricula.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 5:19 PM
 */

#include "Matricula.h"

Matricula::Matricula() {
}

Matricula::Matricula(const Matricula& orig) {
}

Matricula::~Matricula() {
}

void Matricula::leerAlumnos(){
    ifstream archIn("Alumnos.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    alumnos.crear(archIn);
    
}

void Matricula::imprimirAlumnos(){
    ofstream archOut("prueba.txt", ios::out);
    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    alumnos.imprimir(archOut);
}

void Matricula::cargarNotas(){
    ifstream archIn("Notas.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de notas" << endl;
        exit(1);
    }
    int codigo;
    while(1){
        archIn>>codigo;
        if(archIn.eof())break;
        archIn.get();
        alumnos.BuscarInsertar(archIn,codigo);
    }
}


void Matricula::cargaCursos(){
    ifstream archIn("Cursos.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de curso" << endl;
        exit(1);
    }
    cursos.crear(archIn);
}

void Matricula::imprimirCursos(){
    ofstream archOut("pruebaCursos.txt", ios::out);

    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    cursos.imprimir(archOut);
}
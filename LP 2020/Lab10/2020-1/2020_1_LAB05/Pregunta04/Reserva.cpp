/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reserva.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 09:09 AM
 */

#include "Reserva.h"

Reserva::Reserva() {
}

Reserva::Reserva(const Reserva& orig) {
}

Reserva::~Reserva() {
}

void Reserva::cargarPilas(ifstream&in){
    char t;
    while (1) {
        in>>ws;
        in>>t;
        if (in.eof())break;
        in.get();
        if (t == 'A')
            cAlumno.crear(in);
        else if (t == 'P')
            cProfesor.crear(in);
    }
}

void Reserva::cargarSTL(ifstream&in){
    Aula auxA;
    while(1){
        if(in.eof())break;
        in>>auxA;
        vAula.push_back(auxA);
    }
}

void Reserva::carga(char*nomA,char*nomM){
    ifstream inA(nomA, ios::in);
    if (!inA) {
        cout << "No se puede abrir Aulas" << endl;
        exit(1);
    }
    ifstream inM(nomM, ios::in);
    if (!inM) {
        cout << "No se puede abrir Miembros" << endl;
        exit(1);
    }
    cargarSTL(inA);
    cargarPilas(inM);
    imprimirPila();
    imprimirSTL();
}

void Reserva::imprimirPila(){
    ofstream out("cola_prueba.txt", ios::out);
    if (!out) {
        cerr << "Error al abrir el archivo de pilas_prueba" << endl;
        exit(1);
    }
    cAlumno.imprimir(out);
    cProfesor.imprimir(out);
}

void Reserva::imprimirSTL(){
    ofstream out("vector_prueba.txt", ios::out);
    if (!out) {
        cerr << "Error al abrir el archivo de vector_prueba" << endl;
        exit(1);
    }
    vector<Aula>::iterator it;
    for (it = vAula.begin(); it != vAula.end(); it++) {
        out << *it;
    }
}

void Reserva::asigna(int maxA){
    int contador = 0, comodin = 0, maximoAlumnos=maxA,Naula=0,cantGente=0;
    while (1) {
        char cad[150];
        Alumno auxA;
        Profesor auxP;
        if (Naula>=vAula.size())break;
        Aula auxB=vAula[Naula];
        if (cProfesor.vacia() && cAlumno.vacia())break;
        if (!cAlumno.vacia() && contador < maximoAlumnos) {
            auxA = cAlumno.Pop();
            auxB.SetTipo('A');
            auxB.SetCodigo(auxA.GetCodigo());
            auxA.GetNombre(cad);
            auxB.SetNombre(cad);
            contador++;
        }
        else if (!cProfesor.vacia()) {
            auxP = cProfesor.Pop();
            auxB.SetTipo('P');
            auxB.SetCodigo(auxP.GetCodigo());
            auxP.GetNombre(cad);
            auxB.SetNombre(cad);
        } 
        cantGente++;
        if(cantGente>=auxB.GetCapacidad()){
            Naula++;
            contador=0;
            cantGente=0;
        }
        if (cProfesor.vacia() || cAlumno.vacia())contador = 0;
        vAula.push_back(auxB);
        comodin++;
    }
    
   
}

void Reserva::imprimirAulas(){
    ofstream out("Asignaciones.txt", ios::out);
    if (!out) {
        cerr << "Error al abrir el archivo de Asignaciones" << endl;
        exit(1);
    }
    out<<setw(70)<<"Reservas Asignadas"<<endl;
    
    for (int it=0; it <= vAula.size(); it++) {
        if(vAula[it].GetTipo()=='A' || vAula[it].GetTipo()=='P'){
            out << vAula[it];
        }
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Superclase.cpp
 * Author: crimson
 * 
 * Created on July 16, 2020, 2:41 PM
 */

#include "Superclase.h"

Superclase::Superclase() {
}

Superclase::Superclase(const Superclase& orig) {
}

Superclase::~Superclase() {
}

void Superclase::CargarPilas() {
    ifstream in("Miembros.csv", ios::in);
    if (!in) {
        cerr << "Error al abrir el archivo de Miembros" << endl;
        exit(1);
    }
    char t;
    while (1) {
        in>>ws;
        in>>t;
        if (in.eof())break;
        in.get();
        if (t == 'A')
            lalumnos.crear(in);
        else if (t == 'P')
            lprofesores.crear(in);
    }
}

void Superclase::ImprimirColas() {
    ofstream out("r-pila.txt", ios::out);
    if (!out) {
        cerr << "Error al abrir el archivo de r" << endl;
        exit(1);
    }
    lalumnos.imprimir(out);
    lprofesores.imprimir(out);
}

void Superclase::CargarSTL() {
    int contador = 0;
    char cad[150];
    while (1) {
        Alumno auxA;
        Profesor auxP;
        ListaBanco auxB;
        if (lalumnos.vacia() && lprofesores.vacia())break;
        if (!lprofesores.vacia() && contador < 3) {
            auxP = lprofesores.Desapilar();
            auxB.SetTipo('P');
            auxB.SetCod(auxP.GetCod());
            auxP.GetNom(cad);
            auxB.SetNom(cad);
            contador++;
        } else if (!lalumnos.vacia()) {
            auxA = lalumnos.Desapilar();
            auxB.SetTipo('A');
            auxB.SetCod(auxA.GetCod());
            auxA.GetNom(cad);
            auxB.SetNom(cad);
            contador = 0;
        }
        if (lalumnos.vacia() || lprofesores.vacia())contador = 0;
        Banco.push_back(auxB);
    }
}

void Superclase::ImprimirSTL() {
    ofstream out("todoLisa.txt", ios::out);
    if (!out) {
        cerr << "Error al abrir el archivo de r" << endl;
        exit(1);
    }
    list<ListaBanco>::iterator it;
    for (it = Banco.begin(); it != Banco.end(); it++) {
        out << *it;
    }
    //    for(int i=0;i<Banco.size();i++){
    //        out<<Banco[i];
    //    }
}
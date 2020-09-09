/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SuperClase.cpp
 * Author: crimson
 * 
 * Created on July 15, 2020, 5:23 PM
 */

#include "SuperClase.h"

SuperClase::SuperClase() {
}

SuperClase::SuperClase(const SuperClase& orig) {
}

SuperClase::~SuperClase() {
}

void SuperClase::CargarColas(){
    ifstream in("Miembros.csv", ios::in);
    if(!in){
        cerr << "Error al abrir el archivo de Miembros" << endl;
        exit(1);
    }
    char t;
    while(1){
        in>>ws;
        in>>t;
        if(in.eof())break;
        in.get();
        if(t=='A')
            alumnos.crear(in);
        else if(t=='P')
            profesores.crear(in);
    }
}

void SuperClase::ImprimirColas(){
    ofstream out("r-pila.txt", ios::out);
    if(!out){
        cerr << "Error al abrir el archivo de r" << endl;
        exit(1);
    }
    alumnos.imprimir(out);
    profesores.imprimir(out);
}

void SuperClase::CargarSTL(){
    int contador=0;
    char cad[150];
    while(1){
        Alumno auxA;
        Profesor auxP;
        ListaBanco auxB;
        if(alumnos.vacia() && profesores.vacia())break;
        if(!profesores.vacia() && contador<3){
            auxP=profesores.Desapilar();
            auxB.SetTipo('P');
            auxB.SetCod(auxP.GetCod());
            auxP.GetNom(cad);
            auxB.SetNom(cad);
            contador++;
        }
        else if(!alumnos.vacia()){
            auxA=alumnos.Desapilar();
            auxB.SetTipo('A');
            auxB.SetCod(auxA.GetCod());
            auxA.GetNom(cad);
            auxB.SetNom(cad);
            contador=0;
        }
        if(alumnos.vacia() || profesores.vacia())contador=0;
        Banco.push_back(auxB);
    }
}

void SuperClase::ImprimirSTL(){
    ofstream out("todoLisa.txt", ios::out);
    if(!out){
        cerr << "Error al abrir el archivo de r" << endl;
        exit(1);
    }
    vector<ListaBanco>::iterator it;
    for(it=Banco.begin();it!=Banco.end();it++){
        out<<*it;
    }
//    for(int i=0;i<Banco.size();i++){
//        out<<Banco[i];
//    }
}


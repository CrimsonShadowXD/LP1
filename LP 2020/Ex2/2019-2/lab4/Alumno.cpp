/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: crimson
 * 
 * Created on July 15, 2020, 9:24 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    nom=NULL;
    cod=-1;
    tipo='&';
}

Alumno::Alumno(const Alumno& orig) {
    nom=NULL;
    *this = orig;
}

Alumno::~Alumno() {
}

void Alumno::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Alumno::GetTipo() const {
    return tipo;
}

void Alumno::SetCod(int cod) {
    this->cod = cod;
}

int Alumno::GetCod() const {
    return cod;
}

void Alumno::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void Alumno::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}

void Alumno::CargarNotas(){
    char cad[10],s,t;
    int cod,nota,ciclo,periodo;
    double cred;
    Curso aux;
    ifstream in("Cursos.txt", ios::in);
    if(!in){
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    cout<<this->lcurso.size()<<' '<<GetCod()<<' ';
    while(1){
        in>>cod;
        if(in.eof())break;
        in>>cad>>nota>>ciclo>>s>>periodo>>cred>>t;
        in>>ws;
        if(cod==GetCod()){
            aux.SetCcurso(cad);
            aux.SetCiclo(ciclo*10+periodo);
            aux.SetCredito(cred);
            aux.SetNota(nota);
            this->lcurso.push_back(aux);
        }
    }
//    if(lcurso.empty())cout<<"esta vacio"<<endl;
//    else cout<<"Pushea "<<this->lcurso.size()<<endl;
}

void Alumno::ImprimirCursos(ofstream&out){
    list<Curso>::iterator it;
    for(it=lcurso.begin();it!=lcurso.end();it++){
        out<<*it<<endl;
    }
    
}

bool Alumno::vacioCurso(){
    return lcurso.empty();
}

void Alumno::operator=(const Alumno&a){
    char cad[150];
    a.GetNom(cad);
    SetNom(cad);
    SetCod(a.GetCod());
    SetTipo(a.GetTipo());
    list<Curso>::const_iterator it_orig;
    it_orig=a.lcurso.begin();
    for(it_orig;it_orig!=a.lcurso.end();it_orig++){
        lcurso.push_back(*it_orig);
    }
}

ofstream& operator<<(ofstream&out, Alumno&a){
    char cad[150];
    a.GetNom(cad);
    out<<cad<<' ';
    out<<a.GetCod()<<' ';
    out<<a.GetTipo()<<endl;
    for(int i=0;i<150;i++)out<<'=';out<<endl;
    if(a.vacioCurso()) cout<<"vacio "<<a.GetCod()<<endl;
    else a.ImprimirCursos(out);
    return out;
}

void operator>>(ifstream&in, Alumno&a){
    char t,cad[150],buff[500];
    int cod;
    in>>ws;
    in>>t; a.SetTipo(t);
    in>>ws;
    in>>cod;a.SetCod(cod);
    in>>ws;
    in>>cad;a.SetNom(cad);
    in.getline(buff,500);  
    a.CargarNotas(); 
    if(a.vacioCurso())cout<<"esta vacio"<<endl;
    else cout<<"Pushea "<<endl;
}

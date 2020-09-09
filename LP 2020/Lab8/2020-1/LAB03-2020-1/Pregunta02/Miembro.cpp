
/* 
 * File:   Miembro.cpp
 * Author: Rodrigo Agama    Codigo:20151460
 * 
 * Created on 3 de julio de 2020, 08:06
 */

#include "Miembro.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

Miembro::Miembro() {
    this->lalumno=nullptr;
    this->lprofesor=nullptr;
}


Miembro::~Miembro() {
    if (lalumno) delete[] lalumno;
    if (lprofesor) delete[] lprofesor;
}

void Miembro::leerMiembro(ifstream &in){
    char c; char buff[200]; int codigo,escala;
    c=in.get(); in.get(); if (in.eof()) return; Profesor nuevo;
    if (c=='P'){
        Profesor nuevo;
        nuevo.leer(in);
        if (in.eof()) return;
        cout<<nuevo.GetCodigo();
        (*this)+nuevo;
    }
    else if (c=='A'){
        Alumno nuevo;
        nuevo.leer(in);
        if (in.eof()) return;
        (*this)+nuevo;
    }
        
}

  void Miembro::operator+(Alumno &entrada){
      this->agregarAlumno(entrada);
  }
    void Miembro::operator+(Profesor &entrada){
        this->agregarProfesor(entrada);
    }

void Miembro::agregarAlumno(Alumno &nuevo){
       static int n=0;
       Alumno vacio; 
       vacio.SetCodigo(-1); 

    if (n==0){
        n++;
        this->lalumno = new Alumno[n+1];
        lalumno[0]=nuevo;
        lalumno[1]=vacio;
        
    }
    else{ //Si tengo 2 elementos (n=3), 
        Alumno *aux;
        n++;
        aux = new Alumno [n+1];
        for( int i=0; i<n; i++) aux[i]=lalumno[i];
        aux[n+1]=vacio;
        aux[n]=nuevo;
        delete lalumno;
        lalumno=aux;
        n++;
    }
    return;
    
}

void Miembro::agregarProfesor(Profesor &nuevo){
    static int n=0; Profesor vacioP; vacioP.SetCodigo(-1);
    if (n==0){
        n++;
        this->lprofesor = new Profesor[n+1];
        lprofesor[0]=nuevo;
        lprofesor[1]=vacioP;        
    }
    else{ //Si tengo 2 elementos (n=3), 
        Profesor *aux;
        n++;
        aux = new Profesor [n+1];
        for( int i=0; i<n+1; i++) aux[i]=lprofesor[i];
        aux[n+1]=vacioP;
        aux[n]=nuevo;
        delete lprofesor;
        lprofesor=aux;
        n++;
    }
    return;
    
}

void Miembro::imprimir(char *nombreA, char *nombreP){
    ofstream outA(nombreA,ios::out);
    ofstream outP(nombreP,ios::out);
    if (!outA){
        cout<<"Error creando el nombre del reporte de Alumnos."<<endl; exit(1);}
    if (!outP){
        cout<<"Error creando el nombre del reporte de Profesores."<<endl; exit(1);}
    outA<<setw(20)<<' '<<"Miembros Alumnos"<<endl;
    outP<<setw(20)<<' '<<"Miembros profesores"<<endl;
    
    for (int i=0; lalumno[i].GetCodigo()!=-1 ; i++){
        lalumno[i].imprimir(outA);
    }
    for (int i=0; lprofesor[i].GetCodigo()!=-1 ; i++){
        lalumno[i].imprimir(outP);
    }
}


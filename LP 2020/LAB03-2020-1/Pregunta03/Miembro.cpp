/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:07 AM
 */

#include "Miembro.h"
#include "sobrecarga.h"

Miembro::Miembro() {
    lalumno=NULL;
    lprofesor=NULL;
}

Miembro::Miembro(const Miembro& orig) {
}

Miembro::~Miembro() {
}

void Miembro::incrementarAlum(int &n,int &c){
    c+=5;
    if(lalumno==NULL){
        lalumno=new Alumno[c];
    }
    else{
        Alumno *Aux;
        Aux=new Alumno[c];
        for(int i=0;i<n;i++){
            Aux[i]=lalumno[i];
        }
        lalumno=Aux;
    }
}

void Miembro::incrementarProf(int &n,int &c){
    c+=5;
    if(lprofesor==NULL){
        lprofesor=new Profesor[c];
    }
    else{
        Profesor *Aux;
        Aux=new Profesor[c];
        for(int i=0;i<n;i++){
            Aux[i]=lprofesor[i];
        }
        lprofesor=Aux;
    }
}

bool Miembro::VacioA(){
    return (lalumno==NULL);
}

bool Miembro::VacioP(){
    return (lprofesor==NULL);
}


void Miembro::imprime(){
    ofstream archP("Profesores.txt",ios::out);
//    if(!archP){        
//        cout << "No se puede abrir";        
//                exit(1);    
//    }
    int i=0;
    while(1){
        if(lprofesor[i].GetCodigo()<0)
            break;
        archP<<lprofesor[i];
        i++;        
    }  
    
    ofstream archA("Alumnos.txt",ios::out);
//    if(!archA){        
//        cout << "No se puede abrir";        
//        exit(1);    
//    }
    int j=0;
    while(1){
        if(lalumno[j].GetCodigo()<0)
            break;
        archA<<lalumno[j];
        j++;        
    } 
}
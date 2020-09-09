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

Miembro::Miembro() {
    lalumno=NULL;
    lprofesor=NULL;
}

Miembro::Miembro(const Miembro& orig) {
}

Miembro::~Miembro() {
}

void Miembro::operator +(const Alumno &Alum){
    if(lalumno!=NULL){
        int i=0;
        while(1){
            if(lalumno[i].GetCodigo()<0){
                break;
            }
        }
        lalumno[i]=Alum;
        i++;
    }
}

void Miembro::operator +(const Profesor &prof){
    if(lprofesor!=NULL){
        int i=0;
        while(1){
            if(lprofesor[i].GetCodigo()<0){
                break;
            }
        }
        lprofesor[i]=prof;
        i++;
    }
}
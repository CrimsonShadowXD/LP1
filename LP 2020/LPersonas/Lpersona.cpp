/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lpersona.cpp
 * Author: cueva
 * 
 * Created on 7 de julio de 2020, 11:19 AM
 */
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Persona.h"
#include "Profesor.h"
#include "Alumno.h"
#include "Lpersona.h"
#include "Sobrecarga.h"

 Lpersona::Lpersona(){
        lpers=NULL;   
 }

 void Lpersona::lee(char *nom){
    char tipo;
    Persona *p;
    ifstream arch(nom,ios::in);
    if(!arch)
    {   cout << "Archivo no encontrado" << endl;         
        exit(1);
    }
    
    while(1){
        arch.get(tipo);
        if(arch.eof()) break;
        arch.get();
        if(tipo=='A') p = new Alumno;
        else
            p = new Profesor;
        //p->lee(arch);
        arch >> p;
        inserta(p);
    }
}
 
void Lpersona::inserta(Persona *&pers){
    Npersona *p = lpers;
    Npersona *nuevo,*ant=NULL;
        
    nuevo = new Npersona;
    nuevo->pers = pers;
    
    while(p){
        ant=p;
        p=p->sig;
    }
    if(ant==NULL) lpers = nuevo;
    else
        ant->sig = nuevo;

}
    
void Lpersona::imprime(char *nom){
        class Npersona *p;
        
        ofstream arch(nom,ios::out);
        if(!arch)
        {   cout << "Archivo no encontrado" << endl;
             exit(1);
        }
        p=lpers;
        
        while(p)
        {   ///p->pers->imprime(arch);
            arch << p->pers;
            p=p->sig;
        }
   }



void Lpersona::busca(int dni, char* nombre){
    Npersona *p=lpers;
    
    while(p)
    {   if(p->pers->GetDni()==dni) 
        {   
            p->pers->GetNombre(nombre);
            break;
        }    
        
        p=p->sig;
    }
    
    
}
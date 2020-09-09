/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAlumnos.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 5:18 AM
 */

#include "ListaAlumnos.h"

ListaAlumnos::ListaAlumnos() {
    inicio=NULL;
}

ListaAlumnos::ListaAlumnos(const ListaAlumnos& orig) {
}

ListaAlumnos::~ListaAlumnos() {
}

void ListaAlumnos::crear(ifstream&in){
    NodoAlumno *nuevo;
    while(1){
        nuevo=new NodoAlumno;
        nuevo->elem.leerAl(in);
        if(in.eof())break;
        this->insertar(nuevo);        
    }
}

void ListaAlumnos::insertar(NodoAlumno*nuevo){
    NodoAlumno *p,*ant;
    ant=NULL;
    p=inicio;
    while(p){
//        if(p->elem > nuevo->elem)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
//    nuevo->ant=ant;
//    if(p)p->ant=nuevo;
    if(ant)ant->sig=nuevo;
    else inicio=nuevo;
}

void ListaAlumnos::imprime(ofstream&out){
    NodoAlumno *p;
    p=inicio;
    while(p){
        p->elem.imprimirAl(out);
        p=p->sig;
        out<<endl;
    }

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 4:59 PM
 */

#include "ListaConductores.h"
#include "NodoC.h"

ListaConductores::ListaConductores() {
    Inicio=NULL;
    Fin=NULL;
}

ListaConductores::ListaConductores(const ListaConductores& orig) {
}

ListaConductores::~ListaConductores() {
}

void ListaConductores::insertar(NodoC *nuevo){
    NodoC *p,*ant;
    ant=NULL;
    p=Inicio;
    while(p){
        if(p->elem > nuevo->elem)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    nuevo->ant=ant;
    if(p)p->ant=nuevo;
    if(ant)ant->sig=nuevo;
    else Inicio=nuevo;
}

void ListaConductores::crear(ifstream&in){
    NodoC *nuevo;
    while(1){
        nuevo=new NodoC;
        nuevo->elem.leer(in);
        if(in.eof())break;
        this->insertar(nuevo);        
    }
}

void ListaConductores::imprimir(ofstream&out){
    NodoC *p;
    p=Inicio;
    while(p){
        p->elem.imprimir(out);
        p=p->sig;
        out<<endl;
    }
}

void ListaConductores::cargarinfracciones(ifstream&in){
    
    int dni, infracc;
    char cad[10];
    NodoC *p;
    
    
    while(1){
        p=Inicio;
        in>>dni;
        if(in.eof())break;
        in.get();
        in.getline(cad,10,',');
        in>>infracc;
        cout<<infracc<<endl;
        while(p){
            if(p->elem.getDni()==dni){
                p->elem.cargaInfracc(cad,infracc);
                break;
            }
            p=p->sig;
        }
    }
}

void ListaConductores::Calc_Impr_Montos(ofstream&out,ListaDoble<Infracciones> l){
    NodoC *p;
    char cad[100];
    int *montos;
    p=Inicio;
    while(p){
        p->elem.getNombre(cad);
        out<<cad<<p->elem.getDni()<<p->elem.getTelefono()<<endl;
        montos=p->elem.ObtenerM();
        p=p->sig;
    }
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaVehiculos.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 4:59 PM
 */

#include "ListaVehiculos.h"
#include "NodoV.h"

ListaVehiculos::ListaVehiculos() {
    Inicio=NULL;
    Fin=NULL;
}

ListaVehiculos::ListaVehiculos(const ListaVehiculos& orig) {
}

ListaVehiculos::~ListaVehiculos() {
}

void ListaVehiculos::insertar(NodoV *nuevo){
    NodoV *p,*ant;
    ant=NULL;
    p=Inicio;
    while(p){
        if(p->elem>nuevo->elem){
            break;
        }
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    nuevo->ant=ant;
    if(p)p->ant=nuevo;
    if(ant)ant->sig=nuevo;
    else Inicio=nuevo;
}

void ListaVehiculos::crear(ifstream&in){
    NodoV *nuevo;
    while(1){
        nuevo=new NodoV;
        nuevo->elem.leer(in);
        if(in.peek()==',')in.get();
        if(in.peek()=='\n')break;
        this->insertar(nuevo);
    }
}

void ListaVehiculos::imprimir(ofstream&out){
    NodoV *p;
    p=Inicio;
    while(p){
        p->elem.imprimir(out);
        p=p->sig;
    }
    out<<endl;
}

void ListaVehiculos::cargarinfr(char*cad,int infr){
    char placa[10];
    NodoV *p;
    p=Inicio;
    cout<<cad<<' ';
    while(p){
        p->elem.GetPlaca(placa);
        if(strcmp(placa,cad)==0){
            cout<<placa<<endl;
            p->elem.anadir(infr);
            break;
        }
        p=p->sig;
    }
}
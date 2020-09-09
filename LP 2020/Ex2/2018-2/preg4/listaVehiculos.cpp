/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaVehiculos.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 6:37 AM
 */

#include "listaVehiculos.h"

listaVehiculos::listaVehiculos() {
    inicio=NULL;
    ultimo=NULL;
}

listaVehiculos::listaVehiculos(const listaVehiculos& orig) {
}

listaVehiculos::~listaVehiculos() {
}


void listaVehiculos::cargar(ifstream&in){
    NodoVehiculo *nuevo;
    while(1){
        nuevo=new NodoVehiculo;
        nuevo->elem.leer(in);
        char c=in.get();
        this->insertar(nuevo);
        if(c==13 || c=='\n')break;        
    }
}

void listaVehiculos::insertar(NodoVehiculo *nuevo){
    NodoVehiculo *p,*ant;
    ant=NULL;
    p=inicio;
    while(p){
//        if(p->elem > nuevo->elem)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    nuevo->ant=ant;
    if(p!=NULL){
        p->ant=nuevo;
    }
    else{
        ultimo=nuevo;
    }
    if(ant!=NULL){
        ant->sig=nuevo;
    }
    else inicio=nuevo;
}

void listaVehiculos::imprimir(ofstream&out){
    NodoVehiculo *p;
    p=inicio;
    while(p){
        p->elem.imprimir(out);
        p=p->sig;
    }
    out<<endl;
    out<<endl;
}

void listaVehiculos::imprimirRev(ofstream&out){
    NodoVehiculo *p;
    p=ultimo;
    while(p){
        p->elem.imprimir(out);
        p=p->ant;
    }
    out<<endl;
    out<<endl;
}

void listaVehiculos::imprimirOrden(ofstream&out,int orden){
    if(orden==1){
        imprimirRev(out);
    }
    else{
        imprimir(out);
    }
}

int* listaVehiculos::devolverTodasLasfaltas(){
    NodoVehiculo *p;
    p=inicio;
    int *aux,j=0,*ret;
    aux=new int[100];
    while(p){
        ret=p->elem.DevolverFaltas();
        if(ret!=NULL){
            for(int i=0;ret[i]!=-1;i++){
                aux[j]=ret[i];
                j++;
            }
        }
        p=p->sig;
    }
    aux[j]=-1;
    return aux;
}
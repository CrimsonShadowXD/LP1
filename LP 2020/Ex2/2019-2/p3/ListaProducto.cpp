/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaProducto.cpp
 * Author: crimson
 * 
 * Created on July 14, 2020, 1:11 PM
 */

#include "ListaProducto.h"

ListaProducto::ListaProducto() {
    inicio=NULL;
}

ListaProducto::ListaProducto(const ListaProducto& orig) {
}

ListaProducto::~ListaProducto() {
}

void ListaProducto::crear(ifstream&in){
    NodoProducto *nuevo;
    while(1){
        nuevo=new NodoProducto;        
        if(in.eof())break;
        nuevo->elem.leer(in);
        this->insertar(nuevo);        
    }
}

void ListaProducto::insertar(NodoProducto*nuevo){
    NodoProducto *p,*ant;
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

void ListaProducto::imprime(ofstream&out){
    NodoProducto *p;
    p=inicio;
    while(p){
//        p->elem.imprimirP(out);
        p=p->sig;
        out<<endl;
    }
}

void ListaProducto::impPcod(ofstream&out){
    NodoProducto *p;
    char cad[30];
    p=inicio;
    while(p){
//        p->elem.imprimirP(out);
        p->elem.GetCod(cad);
        out<<cad<<';'<<endl;
        p=p->sig;
        out<<endl;
    }
}

void ListaProducto::llenarPallet(ifstream&in){
    
    char cad[10],auxCad[10];
    int found;
    NodoProducto *p;    
    while(1){
        found=0;
        p=inicio;
        in.getline(cad,10,',');
        if(in.eof())break;
        while(p){
            p->elem.GetCod(auxCad);
//            cout<<cad<<' ';
//            cout<<auxCad<<endl;
    //        cout<<strcmp(auxCad,cad)<<endl;
            if(strcmp(auxCad,cad)==0){
                p->elem.llenarP(in);
                found=1;
                break;
            }
            p=p->sig;
        }
        if(!found){
            char tipo[3],cad[50];
            in.getline(tipo,3,',');
            in.getline(cad,50);
            exit(1);
        }
    }
}

void ListaProducto::impLP(ofstream&out){
    NodoProducto *p;
    char cad[30];
    p=inicio;
    while(p){
//        p->elem.imprimirP(out);
        p->elem.imprimir(out);
        p=p->sig;
        out<<endl;
    }
}

void ListaProducto::leerPedidos(ifstream&in){
    char cad[10],auxCad[10];
    int found;
    NodoProducto *p;    
    while(1){
        found=0;
        p=inicio;
        in.getline(cad,10,',');
        if(in.eof())break;
        while(p){
            p->elem.GetCod(auxCad);
//            cout<<cad<<' ';
//            cout<<auxCad<<endl;
            if(strcmp(auxCad,cad)==0){
//                cout<<"exito"<<endl;
                p->elem.llenarPedidos(in);
                found=1;
                break;
            }
            p=p->sig;
        }
        if(!found){
            int cod;
            double kg;
            in>>cod;
            in.get();
            in>>kg;
            in>>ws;
//            cout<<"WTF"<<endl;
            exit(1);
        }
    }
}

void ListaProducto::impCPed(ofstream&out){
    NodoProducto *p;
    char cad[30];
    p=inicio;
    while(p){
//        p->elem.imprimirP(out);
        p->elem.imprimirPedidos(out);
        p=p->sig;
        out<<endl;
    }
}

void ListaProducto::atenderPedidos(){
    NodoProducto *p;
    p=inicio;
    while(p){
        p->elem.atPedidos();
        p=p->sig;
    }
}



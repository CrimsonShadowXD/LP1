/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaVehiculos.cpp
 * Author: Rodrigo
 * 
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#include "ListaVehiculos.h"
#include <cstring>
#include <list>
#include <iterator>

ListaVehiculos::ListaVehiculos() {
    lista = NULL;
}

ListaVehiculos::~ListaVehiculos() {
}

    void ListaVehiculos::insertar(NodoV *nuevo){
        NodoV *p,*ant;
        ant=NULL;
        p=lista;
        
        while(p){
            if (p->elem>nuevo->elem) break;            
            ant=p;
            p=p->sig;            
        }
        nuevo->sig = p;
        nuevo->ant = ant;
        
        if(p) p->ant=nuevo;
        if(ant) ant->sig=nuevo;
        else lista = nuevo;
        
    }
    void ListaVehiculos::multar(char *placa, int codigo){
        NodoV *p;
        p=lista;
        while(p){
            if(strcmp(p->elem.getPlaca(),placa)==0) {p->elem.multar(codigo);break;}
            p=p->sig;
        }
        
    }
    
    void ListaVehiculos::crear(ifstream &in){
        NodoV *nuevo;
        while(1){
            nuevo = new NodoV;
            nuevo->elem.leer(in);
            insertar(nuevo);
            if(in.peek()==',') in.get();
            if(in.peek()=='\n') break;
        }
        
    }
    void ListaVehiculos::imprimir(ofstream &out){
        NodoV *p;
        
        p=lista;
        out<<"Vehiculos: "<<endl;
        while(p){
            p->elem.imprimir(out);
            p=p->sig;
        }
        
    }

    int* ListaVehiculos::obtenerMultas(){
        NodoV *p;
        int n=0, *salida;
        int buff[500];
        
        p=lista;
        while(p){
            int *aux;
            aux=p->elem.obtenerMultas();
            for(int i=0;aux[i]!=-1;i++){
                buff[n]=aux[i];
                n++;
            }            
            p=p->sig;
        }
        salida = new int [n+1];
        for(int i=0;i<n;i++) salida[i]=buff[i];
        salida[n]=-1;
        return salida;
    }
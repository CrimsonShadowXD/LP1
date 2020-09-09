/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.h
 * Author: crimson
 *
 * Created on July 5, 2020, 10:52 PM
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Nodo.h"

using namespace std;

template <typename T>
class ListaDoble{
    private:
        Nodo<T> *lista;
        Nodo<T> *ultimo;
        public:
            ListaDoble();
            void leer(ifstream &in);
            void imprimir(ofstream &out, int modo);
            
            void insertar(Nodo<T> *nuevo);
            double buscarMonto(int codigo);          
            
        
};

template <typename T>
ListaDoble<T>::ListaDoble(){
    lista=NULL;
    ultimo=NULL;    
}

template <typename T>
void ListaDoble<T>::leer(ifstream &in){
       Nodo<T> *nuevo;
        
        while(1){
            nuevo = new Nodo<T>;
            nuevo->elem.leer(in);
            if (in.eof()) break;  
            this->insertar(nuevo);
        }
        
}
template <typename T>
void ListaDoble<T>::imprimir(ofstream &out, int dir){
    Nodo<T> *p; 
    out<<"REPORTE:"<<endl;
    if (dir==0){
        p=this->lista;      
        out<<"Ascendente: "<<endl;
        while (p){               
            p->elem.imprimir(out);
            p=p->sig; out<<endl;     
        }
    }
    else if (dir==1){
        out<<"Descendente"<<endl;
        p=this->ultimo;
        while (p){
            p->elem.imprimir(out);
            p=p->ant; out<<endl;    
        }      
    }     

}

template <typename T>
 void ListaDoble<T>::insertar(Nodo<T> *nuevo){
    Nodo<T> *p,*ant;
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
    else ultimo=nuevo;
    if(ant) ant->sig=nuevo;
    else lista = nuevo;

}

template <typename T>
double ListaDoble<T>::buscarMonto(int codigo){
    Nodo<T> *p;
    p=this->lista;
    while(p){
        if (p->elem.getCodigo()==codigo)     return p->elem.getMonto();
        p = p->sig;
    }
                
    return 0;
}


#endif /* LISTADOBLE_H */


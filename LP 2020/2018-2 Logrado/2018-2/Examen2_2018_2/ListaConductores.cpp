/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.cpp
 * Author: Rodrigo
 * 
 * Created on 7 de diciembre de 2019, 02:29 PM
 */

#include "ListaConductores.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;



    ListaConductores::ListaConductores(){
        lista=NULL;
        
    }
    ListaConductores::~ListaConductores(){
        
    }
    
    void ListaConductores::insertar(NodoC *nuevo){
         NodoC *p,*ant;
        ant=NULL;
        p=lista;
        
        //cout<<nuevo->elem.getDni()<<endl;
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
    
    void ListaConductores::multar(int dni,char *placa, int codigo){
         NodoC *p;   
        p=lista;
        
        while(p){
            if (p->elem.getDni()==dni){ p->elem.multar(placa,codigo);    break; }
            p=p->sig;            
        }
        
    }
    
    void ListaConductores::crear(ifstream &in){
        NodoC *nuevo;
        
        while(1){
            nuevo = new NodoC;
            nuevo->elem.leer(in);
            if (in.eof()) break;  
            this->insertar(nuevo);
        }
        
    }
    void ListaConductores::imprimir(ofstream &out){
        NodoC *p; int *agria;
        p=lista;
        out<<"REPORTE DE CONDUCTORES:"<<endl;
        
        for(int i=0;i<70;i++) out<<'=';out<<endl;
        while (p){
            p->elem.imprimir(out);
            for(int i=0;i<70;i++) out<<'-';out<<endl;
            p=p->sig; out<<endl;
        }
        
    }

    void ListaConductores::lecturaMultas(ifstream& in){
        int dni,codigo;
        char placa[100];
        while(1){
            in>>dni;
            if (in.eof()) break;
            in.get(); 
            in.getline(placa,100,',');
            in>>codigo; in>>ws;
            this->multar(dni,placa,codigo);
        }
    }
    
    void ListaConductores::imprimirMultas(ofstream& out, ListaDoble<Infraccion> infs){
        NodoC *p;
        p=lista;
        out<<"                      Entidad Reguladora de Transito"<<endl;
        for(int i=0;i<100;i++) out<<'=';out<<endl;
        out<<"    DNI            Nombre                             Telefono      Monto"<<endl;
        for(int i=0;i<100;i++) out<<'=';out<<endl;
        while(p){
            out<<p->elem.getDni()<<" "<<p->elem.getNombre()<<setw(45-strlen(p->elem.getNombre()))<<' '; out<<p->elem.getTelefono()<<"     ";
            int *multas; double monto=0;
            multas=p->elem.obtenerMultas();
            //OBTENER 
            for(int j=0;multas[j]!=-1;j++) monto+=infs.buscarMonto(multas[j]);
            out<<fixed<<setprecision(2)<<monto<<endl;
            p=p->sig;
        }
        
    }


   
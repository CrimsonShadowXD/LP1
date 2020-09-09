/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   contenedor.cpp
 * Author: crimson
 * 
 * Created on July 3, 2020, 2:18 AM
 */

#include "contenedor.h"

contenedor::contenedor() {
    ArrInt=NULL;
    ArrNac=NULL;
}

contenedor::contenedor(const contenedor& orig) {
}

contenedor::~contenedor() {
}

void contenedor::incrementarInt(int &n_Int,int &cap_Int){
    cap_Int+=5;
    if(ArrInt==NULL){
        ArrInt=new Intercambio[cap_Int];
    }
    else{
        Intercambio *Aux;
        Aux=new Intercambio[cap_Int];
        for(int i=0;i<n_Int;i++){
            Aux[i]=ArrInt[i];
        }
        ArrInt=Aux;
    }
}

void contenedor::incrementarNac(int &n_Nac,int &cap_Nac){
    cap_Nac+=5;
    if(ArrNac==NULL){
        ArrNac=new Nacional[cap_Nac];
    }
    else{
        Nacional *Aux;
        Aux=new Nacional[cap_Nac];
        for(int i=0;i<n_Nac;i++){
            Aux[i]=ArrNac[i];
        }
        ArrNac=Aux;
    }
}

void contenedor::lee(int &n_Int,int &n_Nac,int &cap_Nac,int &cap_Int){
    char tipo;
    
    ifstream arch("Alumnos.csv",ios::in);
    if(!arch){
        cerr<<"error"<<endl;
        exit(1);
    }
    while(1){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        cout<<tipo<<endl;
        if(tipo=='I'){
            if(n_Int==cap_Int-1||ArrInt==NULL)incrementarInt(n_Int,cap_Int);
            cout<<n_Int<<' '<<cap_Int<<endl;
            arch>>ArrInt[n_Int];
            n_Int++;
        }
        else if(tipo=='R'){
            if(n_Nac==cap_Nac-1||ArrNac==NULL)incrementarNac(n_Nac,cap_Nac);
            cout<<n_Nac<<' '<<cap_Nac<<endl;
            arch>>ArrNac[n_Nac];
            n_Nac++;
        }
    }
}

void contenedor::imprimeNac(int n_Nac){
    ofstream arch("Nacionales.txt",ios::out);
    for(int i=0;i<n_Nac;i++){
        arch<<ArrNac[i];
    }
}


void contenedor::imprimeInt(int n_Int){
    ofstream arch("Internacionales.txt",ios::out);
    for(int i=0;i<n_Int;i++){
        arch<<ArrInt[i];
    }    
}
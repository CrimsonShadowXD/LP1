/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Nombre: Leandro Lazo La Rosa
 * Codigo: 20130263
 */

#include "ClaseHorarios.h"

Horarios::Horarios(){
    hora=0;
    min=0;
    seg=0;
    DNI=NULL;
    pasajeros=NULL;
    Llegada=NULL;
    Espera=NULL;
    Salida=NULL;
    TEsperaTotal=0;
    CantPasajeros=0;
}

void Horarios::leer(char* nom){
    class NodoHorarios *aux;
    char *H_Apertura,Nom_Pasaj[100];
    int dni,hh,mm,ss;
    float T_Espera;
    ifstream arch(nom,ios::in);
    if(!arch){
        cerr<<"Error al abrir archivo"<<endl;
        exit(1);
    }
    arch.getline(H_Apertura);
    while(1){
        aux=new NodoHorarios;
        if(arch.eof())break;
        arch>>dni;
        arch.get();
        arch.getline(Nom_Pasaj,100,',');
        arch>>hh;
        arch>>arch.get();
        arch>>mm;
        arch>>arch.get();
        arch>>ss;
        arch>>arch.get();
        arch>>T_Espera;
        arch>>ws;
        DNI.insertar(dni);
        pasajeros.insertar(dni);
        int Llegada_seg=hh*3600+mm*60+ss;
        Llegada.insertar(Llegada_seg);
        Espera.insertar(T_Espera);
        int TSalida=Llegada_seg+T_Espera;
        Salida.insertar(TSalida);
        TEsperaTotal+=T_Espera;
        CantPasajeros++;
    }
    arch.close();
}

void Horarios::mostrar(char *nom){
    ofstream arch(nom,ios::out);
    arch<<"Hora de apertura:  "<<endl;
    
    for(int i=0;i<200;i++)arch<<'='<<endl;
}

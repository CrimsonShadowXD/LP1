/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuentas.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:55 AM
 */

#include "Cuentas.h"

Cuentas::Cuentas() {
}

Cuentas::Cuentas(const Cuentas& orig) {
}

Cuentas::~Cuentas() {
}


void Cuentas::leerCuentas(const char*nomb){
    ifstream archin(nomb, ios::in);
    if (!archin) {
        cout << "No se puede abrir " << nomb<<endl;
        exit(1);
    }
    arbCuentas.crear(archin);
}

void Cuentas::leerTiposDeCambio(const char*nomb){
    ifstream archin(nomb, ios::in);
    if (!archin) {
        cout << "No se puede abrir " << nomb<<endl;
        exit(1);
    }
    Moneda aux;
    while(1){
        if(archin.eof())break;
        archin>>aux;
        monedas[aux.GetSimbolo()]=aux;
        archin>>ws;
    }
}

void Cuentas::ejecutarMovimientos( ){ 
    ifstream in("Transacciones.csv", ios::in);
    if (!in) {
        cout << "No se puede abrir Transacciones" << endl;
        exit(1);
    }
    leerTransacciones(in);
    
}

void Cuentas::reporteDeCuentas(const char*nomb){
    ofstream archout(nomb, ios::out);
    if (!archout) {
        cout << "No se puede abrir " << nomb<<endl;
        exit(1);
    }
    impCabecera(archout);
    arbCuentas.imprimir(archout);
    ejecutarMovimientos( );
}

void Cuentas::leerTransacciones(ifstream&in){
    int cod;
    char tmon,ttrans,c;
    double cant;
    while(1){
        in>>cod;
        if(in.eof())break;
        in.get();
        while(1){
            in>>tmon;
            in>>cant;
            c=in.get();
            in>>ttrans;
            c=in.get();
            if(c=='\n'||c==13)break;
            modificarSaldo(cod,tmon,cant,ttrans);
        }
        cout<<cod<<endl;
    }
}

void Cuentas::modificarSaldo(int n,char c,double f,char b){

}


void Cuentas::impLinea(ofstream&out,char c){
    for(int i=0;i<150;i++)
        out<<c;
    out<<endl;
}

void Cuentas::impCabecera(ofstream&out){
    out<<setw(50)<<"ESTADO DE CUENTAS"<<endl;
    impLinea(out,'=');
    out<<setw(80)<<"SALDO INICIAL DE LAS CUENTAS"<<endl; 
    impLinea(out,'=');
    out<<left<<setw(10)<<"Codigo"<<setw(70)<<"Cliente"<<setw(20)<<"Saldo Inicial"<<"Estado"<<right<<endl;
    impLinea(out,'_');
    
}
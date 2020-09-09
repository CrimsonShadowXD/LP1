/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuenta.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:43 AM
 */

#include "Cuenta.h"

Cuenta::Cuenta() {
    estado=NULL;
    cliente=NULL;
    codigo=-1;
    SetEstado("HABIL");
}

Cuenta::Cuenta(const Cuenta& orig) {
    estado=NULL;
    cliente=NULL;
    *this=orig;
}

Cuenta::~Cuenta() {
    if (estado != NULL) delete estado;
    if (cliente != NULL) delete cliente;
}

void Cuenta::SetSaldo(double saldo) {
    this->saldo = saldo;
}

double Cuenta::GetSaldo() const {
    return saldo;
}

void Cuenta::SetEstado(const char* cad) {
    if (cad == NULL) return;
    if (estado != NULL) delete estado;
    estado = new char[strlen(cad) + 1];
    strcpy(estado, cad); 
}

void Cuenta::GetEstado(char* cad) const {
    if (estado == NULL)
        return;
    strcpy(cad, estado); 
}

void Cuenta::SetCliente(const char* cad) {
    if (cad == NULL) 
        return;
    if (cliente != NULL) 
        delete cliente;
    cliente = new char[strlen(cad) + 1];
    strcpy(cliente, cad); 
}

void Cuenta::GetCliente(char* cad) const {
    if (cliente == NULL)
        return;
    strcpy(cad, cliente); 
}

void Cuenta::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Cuenta::GetCodigo() const {
    return codigo;
}

void Cuenta::leer(ifstream&in) { 
    char cad[150];
    int cod;
    double montoini;
    in>>cod; 
    if(in.eof())return;
    SetCodigo(cod);
    in.get();
    in.getline(cad, 150, ','); 
    SetCliente(cad);
    in>>montoini;
    SetSaldo(montoini);
    in>>ws;
}

void Cuenta::imprimir(ofstream&out) { 
    char cad[150];
    out<<left<<setw(10)<<GetCodigo();
    GetCliente(cad);
    out << setw(70)<< cad <<right;
    out<<setprecision(2)<<fixed;
    out<<setw(10)<<GetSaldo();
    GetEstado(cad);
    out<<setw(6)<<' '<<left<<cad<<right<<endl;
}

void Cuenta::operator=(const Cuenta& x) {
    char cad[150];
    x.GetCliente(cad);
    SetCliente(cad);
    x.GetEstado(cad);
    SetEstado(cad);
    SetCodigo(x.GetCodigo());
    SetSaldo(x.GetSaldo());
}

bool Cuenta::operator==(const Cuenta&x) { 
    return (GetCodigo()==x.GetCodigo());
}

bool Cuenta::operator>(const Cuenta&x) { 
    return (GetCodigo()>x.GetCodigo());
}

bool Cuenta::operator<(const Cuenta&x) { 
    return (GetCodigo()<x.GetCodigo());
}

ofstream& operator<<(ofstream&out, Cuenta&x) {
    x.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Cuenta&x) {
    x.leer(in);
}
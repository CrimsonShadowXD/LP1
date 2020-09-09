/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: cueva
 * 
 * Created on 14 de julio de 2020, 10:31 AM
 */
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Alumno.h"

    Alumno::Alumno() {
        cout <<"Constructor Alumno" << endl;
    }


    int Alumno::GetCodigoa() const {
        
        return codigoa;
    }

    void Alumno::SetCodigoa(int codigoa) {
        this->codigoa = codigoa;
    }

    int Alumno::GetEscala() const {
        return escala;
    }

    void Alumno::SetEscala(int escala) {
        this->escala = escala;
    }
    
    char Alumno::mostrarclase(void){
        return 'A';
        
    }

    void Alumno::lee(ifstream& arch){
        char buff[100];
        int cod;
        
        arch >>  cod;
        this->SetDni(cod);
        arch.get();
        arch.getline(buff,100,';');
        this->SetNombre(buff);
        arch >> codigoa;
        arch.get();
        arch >> escala;
        arch.get();
    }

    void Alumno::imprime(ofstream& arch){
        char cad[50];
        
        this->GetNombre(cad);
        arch << "DNI:"<<this->GetDni()<<setw(30)<<"Nombre:"<<cad<<endl;
        arch << "Codigo de Alumno:"<< codigoa <<setw(20)<<
                "Escala:"<< escala <<endl<<endl;
    }

void Alumno::operator=(const Alumno &orig){
    char cad[50];
    orig.GetNombre(cad);
    this->SetNombre(cad);
    this->SetDni(orig.GetDni());
    
    codigoa=orig.codigoa;
    escala=orig.escala;
}
    
bool Alumno::operator>(const Alumno &p){
    return this->GetDni() > p.GetDni();
}
    
void operator >> (ifstream &arch,Alumno &c){
    c.lee(arch);
}
void operator << (ofstream &arch,Alumno &c){
    c.imprime(arch);
}

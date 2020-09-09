/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: cueva
 * 
 * Created on 14 de julio de 2020, 10:32 AM
 */

#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Persona.h"
#include "Profesor.h"


    Profesor::Profesor() {
    codigop = NULL;
    cout <<"Constructor Profesor" << endl;
    }


void Profesor::GetCodigop(char *cad) const {
        strcpy(cad, codigop);
    }

void Profesor::SetCodigop(char *cad) {
    if (codigop)delete codigop;
    codigop = new char [strlen(cad)+1];
    strcpy(codigop,cad);
}

    int Profesor::GetAntiguedad() const {
        return antiguedad;
    }

    void Profesor::SetAntiguedad(int anhos) {
        this->antiguedad = anhos;
    }

    int Profesor::GetDedicacion() const {
        return dedicacion;
    }

    void Profesor::SetDedicacion(int tipo) {
        this->dedicacion = tipo;
    }

    char Profesor::mostrarclase(void){
        return 'P';
    }
    void Profesor::lee(ifstream& arch){
        char buff[10];    
        int cod;
        
        arch >>  cod;
        this->SetDni(cod);
        arch.get();
        arch.getline(buff,100,';');
        this->SetNombre(buff);
        
        arch.getline(buff,10,';');
        codigop = new char [strlen(buff)+1];
        strcpy(codigop,buff);
        arch >> antiguedad;
        arch.get();
        arch >> dedicacion;
        arch.get();
    }

    void Profesor::imprime(ofstream& arch){
        char cad[50];
        
        this->GetNombre(cad);
        arch << "DNI:"<<this->GetDni()<<setw(30)<<"Nombre:"<<cad<<endl;
        arch << "Codigo Docente:"<< codigop <<setw(15)<<"Dedicacion:"
            << dedicacion<< setw(15)<<"Antiguedad:"<< antiguedad<<endl<<endl;
    }

void Profesor::operator=(const Profesor &orig){
    char cad[50];
    orig.GetNombre(cad);
    
    this->SetNombre(cad);
    this->SetDni(orig.GetDni());
    orig.GetCodigop(cad);
    this->SetCodigop(cad);
    dedicacion = orig.dedicacion;
    antiguedad = orig.antiguedad; 
}

bool Profesor::operator>(const Profesor &p){
    return this->GetDni() > p.GetDni();
}

     
void operator >> (ifstream &arch ,Profesor &c){
    c.lee(arch);
    
}
void operator << (ofstream &arch ,Profesor &c){
    c.imprime(arch);
    
}

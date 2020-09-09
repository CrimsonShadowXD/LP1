/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: cueva
 * 
 * Created on 7 de julio de 2020, 11:01 AM
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


char* Profesor::GetCodigop() const {
        return codigop;
    }

    void Profesor::SetCodigop(char* codigop) {
        this->codigop = codigop;
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
        char buff[100];    
        int dni;
        
        arch >> dni; 
        this->SetDni(dni);
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
        char nombre[100];
        
        this->GetNombre(nombre);
        arch << "DNI:"<<this->GetDni()<<setw(30)<<"Nombre:"<<nombre<<endl;
        arch << "Codigo Docente:"<< codigop <<setw(15)<<"Dedicacion:"
            << dedicacion<< setw(15)<<"Antiguedad:"<< antiguedad<<endl<<endl;
    }

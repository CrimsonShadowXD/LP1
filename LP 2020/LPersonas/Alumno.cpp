/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: cueva
 * 
 * Created on 7 de julio de 2020, 10:53 AM
 */
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Persona.h"
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
        int dni;
        
        arch >> dni; 
        this->SetDni(dni);
        arch.get();
        arch.getline(buff,100,';');
        this->SetNombre(buff);
        
        arch >> codigoa;
        arch.get();
        arch >> escala;
        arch.get();
    }

    void Alumno::imprime(ofstream& arch){
        char nombre[100];
        
        this->GetNombre(nombre);
        arch << "DNI:"<<this->GetDni()<<setw(30)<<"Nombre:"<<nombre<<endl;
        
        arch << "Codigo de Alumno:"<< codigoa <<setw(20)<<
                "Escala:"<< escala <<endl<<endl;
    }

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faltas.cpp
 * Author: cueva
 * 
 * Created on 24 de junio de 2020, 12:22 PM
 */

#include "Faltas.h"

Faltas::Faltas() {
}

Faltas::Faltas(const Faltas& orig) {
    dni = orig.dni;
    codigo = orig.codigo;
    multa = orig.multa;
}

Faltas::~Faltas() {
}

void Faltas::SetMulta(float multa) {
    this->multa = multa;
}

float Faltas::GetMulta() const {
    return multa;
}

void Faltas::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Faltas::GetCodigo() const {
    return codigo;
}

void Faltas::SetDni(int dni) {
    this->dni = dni;
}

int Faltas::GetDni() const {
    return dni;
}

   
Faltas Faltas::operator =(const Faltas& f){
    dni = f.dni;
    codigo = f.codigo;
    multa = f.multa;
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acurso.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:04 AM
 */

#include "Acurso.h"

Acurso::Acurso() {
    codigo=0;
}

Acurso::Acurso(const Acurso& orig) {
}

Acurso::~Acurso() {
}

void Acurso::SetOperacion(char operacion) {
    this->operacion = operacion;
}

char Acurso::GetOperacion() const {
    return operacion;
}

void Acurso::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Acurso::GetCodigo() const {
    return codigo;
}

void Acurso::SetClcurso(Curso clcurso) {
    this->clcurso = clcurso;
}

Curso Acurso::GetClcurso() const {
    return clcurso;
}


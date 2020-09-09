/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ACurso.cpp
 * Author: crimson
 * 
 * Created on July 2, 2020, 7:33 PM
 */

#include "ACurso.h"

ACurso::ACurso() {
    codigo=-1;
}

ACurso::~ACurso() {
}

void ACurso::SetOperacion(char operacion) {
    this->operacion = operacion;
}

char ACurso::GetOperacion() const {
    return operacion;
}

void ACurso::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int ACurso::GetCodigo() const {
    return codigo;
}

void ACurso::AsignarDatosCurso(char *cod,int ciclo,int nota,float credito){
    clcurso.SetCcurso(cod);
    clcurso.SetCiclo(ciclo);
    clcurso.SetNota(nota);
    clcurso.SetCredito(credito);
}

void ACurso::ObtenerCurso(char *cad) const{
    clcurso.GetCcurso(cad);
}

int ACurso::ObtenerCiclo() const{
    return clcurso.GetCiclo();
}

int ACurso::ObtenerNota() const{
    return clcurso.GetNota();
}

float ACurso::ObtenerCredito() const{
    return clcurso.GetCredito();
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 08:20 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Cliente.h"

Cliente::Cliente() {
    nombre=NULL;
 }


Cliente::~Cliente() {
    if(nombre)delete nombre;
}

void Cliente::GetNombre(char* nom) const {
    strcpy(nom,nombre);
}

void Cliente::SetNombre(char* nom) {
    if(nombre)delete nombre;
    nombre=new char[strlen(nom)+1];
    strcpy(nombre,nom);
}


void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::SetTiempoTransaccion(double tiempoTransaccion) {
    this->tiempoTransaccion = tiempoTransaccion;
}

double Cliente::GetTiempoTransaccion() const {
    return tiempoTransaccion;
}

void Cliente::SetSegundoLlegada(int segundoLlegada) {
    this->segundoLlegada = segundoLlegada;
}

int Cliente::GetSegundoLlegada() const {
    return segundoLlegada;
}

void Cliente::SetMinutoLlegada(int minutoLlegada) {
    this->minutoLlegada = minutoLlegada;
}

int Cliente::GetMinutoLlegada() const {
    return minutoLlegada;
}

void Cliente::SetHoraLlegada(int horaLlegada) {
    this->horaLlegada = horaLlegada;
}

int Cliente::GetHoraLlegada() const {
    return horaLlegada;
}

void Cliente::operator=(Cliente& cli) {
    char nom[100];
    cli.GetNombre(nom); SetNombre(nom);
    dni=cli.dni;
    horaLlegada=cli.horaLlegada;
    minutoLlegada=cli.minutoLlegada;
    segundoLlegada=cli.segundoLlegada;
    tiempoTransaccion=cli.tiempoTransaccion;
}


void operator<<(ofstream&archOut,Cliente&cli){
    char nomb[100];
    cli.GetNombre(nomb);
    archOut.precision(2);
    archOut<<left<<setw(15)<<cli.GetDni()<<setw(60)<<nomb;
    //hora llegada
    archOut.fill('0');
    archOut<<right<<setw(2)<<cli.GetHoraLlegada()
            <<":"<<setw(2)<<cli.GetMinutoLlegada()<<":"<<setw(2)<<cli.GetSegundoLlegada();
    archOut.fill(' ');
    archOut<<left<<setw(8)<<" "<<right<<setw(5)<<cli.GetTiempoTransaccion()<<" seg."<<setw(4)<<" "<<"hora de salida";
    
}
void operator>>(ifstream&archIn,Cliente&cli){
    char nomb[100];
    int iden,hLLeg,mLLeg,sLleg;
    double demora;
    
    archIn>>iden;
    if(archIn.eof())return;
    archIn.get();
    archIn.getline(nomb,100,',');
    archIn>>hLLeg;
    archIn.get();
    archIn>>mLLeg;
    archIn.get();
    archIn>>sLleg;
    archIn.get();
    archIn>>demora;
    archIn.get();
    
    cli.SetDni(iden);
    cli.SetHoraLlegada(hLLeg);
    cli.SetMinutoLlegada(mLLeg);
    cli.SetNombre(nomb);
    cli.SetSegundoLlegada(sLleg);
    cli.SetTiempoTransaccion(demora);
}


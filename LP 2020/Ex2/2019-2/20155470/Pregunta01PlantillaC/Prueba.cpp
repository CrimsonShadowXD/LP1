/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prueba.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 09:12 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Prueba.h"

void Prueba::imprimirCabeceras(ofstream& archOut, ifstream& archIn) {
    int horaIni,minIni,segIni;
    char c;
    archIn>>horaIni>>c>>minIni>>c>>segIni>>c;
    archOut.fill('0');
    archOut<<"Hora de apertura: "<<setw(2)<<horaIni<<":"<<setw(2)<<minIni<<":"<<setw(2)<<segIni;
    archOut.fill(' ');
    archOut<<endl<<endl;
    archOut<<right<<setw(75)<<" "<<left<<setw(15)<<"HORA"<<setw(15)<<"TIEMPO"<<setw(15)<<"HORA"<<endl;
    archOut<<left<<setw(15)<<"DNI"<<setw(60)<<"NOMBRE"<<setw(15)<<"DE LLEGADA"<<setw(15)<<"DE ESPERA"<<"DE SALIDA"<<endl;
    imprimirLineas(archOut,'=',150);
}

void Prueba::imprimirLineas(ofstream& archOut, char c, int n) {
    for (int i = 0; i < n; i++) {
        archOut<<c;
    }
    archOut<<endl;
}

void Prueba::leerClientes(ifstream& archIn) {
    clientes.crearCola(archIn);
}

void Prueba::imprimirClientes(ofstream& archOut) {
    clientes.imprimirCola(archOut);
}

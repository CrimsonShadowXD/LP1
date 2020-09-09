/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Superclase.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:31 AM
 */

#include "Superclase.h"

Superclase::Superclase() {
}

Superclase::Superclase(const Superclase& orig) {
}

Superclase::~Superclase() {
}

void Superclase::leer(){
    ifstream archin("numerosEnteros.txt", ios::in);
    if (!archin) {
        cout << "No se puede abrir numerosEnteros" << endl;
        exit(1);
    }
    numerosEnteros.crear(archin);
}

void Superclase::modificar(){
    ofstream archout("prueba_Enteros_Modificados_Linux.txt", ios::out);
    if (!archout) {
        cout << "No se puede abrir pruebaLectura_Enteros_sin_Modificar" << endl;
        exit(1);
    }
    numerosEnteros.modificar(3,1000000.333);
    numerosEnteros.imprimir(archout);
}

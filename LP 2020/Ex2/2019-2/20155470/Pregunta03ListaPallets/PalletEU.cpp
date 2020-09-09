/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletEU.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 09:23 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PalletEU.h"

//PalletEU::PalletEU() {
//    tipo=NULL;
//}
//
//PalletEU::~PalletEU() {
//    if(tipo)delete tipo;
//}

//void PalletEU::GetTipo(char* t) const {
//    strcpy(t,tipo);
//}
//
//void PalletEU::SetTipo(char* t) {
//    if(tipo)delete tipo;
//    tipo=new char[strlen(t)+1];
//    strcpy(tipo,t);
//}


//
//void PalletEU::SetCapacidad(double capacidad) {
//    this->capacidad = capacidad;
//}
//
//double PalletEU::GetCapacidad() const {
//    return capacidad;
//}
//

char PalletEU::devolverTipo() {
    return 'E';
}

void PalletEU::leerDatos(ifstream&archIn) {
    char iden[100];
    archIn.getline(iden,100);
    SetId(iden);
}

void PalletEU::imprimirDatos(ofstream&archOut) {
    char iden[100],tipo;
    GetId(iden);
    tipo=devolverTipo();
    archOut<<right<<setw(5)<<" "<<left<<setw(10)<<iden<<right<<setw(5)<<capacidad<<" kg"<<setw(8)<<" "<<tipo<<endl;
}

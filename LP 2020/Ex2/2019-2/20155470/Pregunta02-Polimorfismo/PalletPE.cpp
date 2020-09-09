/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletPE.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 09:23 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PalletPE.h"

//PalletPE::PalletPE() {
//}
//
//PalletPE::PalletPE(const PalletPE& orig) {
//}
//
//PalletPE::~PalletPE() {
//}

char PalletPE::devolverTipo() {
    return 'P';
}

void PalletPE::leerDatos(ifstream&archIn) {
    char iden[100];
    archIn.getline(iden,100);
    SetId(iden);
}

void PalletPE::imprimirDatos(ofstream&archOut) {
    char iden[100],tipo;
    GetId(iden);
    tipo=devolverTipo();
    archOut<<right<<setw(5)<<" "<<left<<setw(10)<<iden<<right<<setw(5)<<capacidad<<" kg"<<setw(8)<<" "<<tipo<<endl;
}

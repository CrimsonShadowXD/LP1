/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pallet.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 09:59 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Pallet.h"
#include "PalletEU.h"
#include "PalletPE.h"
#include "PalletUS.h"

Pallet::Pallet() {
    basePallet=NULL;
}


Pallet::~Pallet() {
    if(basePallet)delete basePallet;
}

void Pallet::definirTipo(char*tipo) {
    if(strcmp(tipo,"US")==0){
            basePallet=new PalletUS;
        }else if(strcmp(tipo,"EU")==0){
            basePallet=new PalletEU;
        }else if(strcmp(tipo,"PE")==0){
            basePallet=new PalletPE;
        }
}

void Pallet::leerDatos(ifstream&archIn) {
    char iden[100];
    archIn.getline(iden,100);
    //leemos el identificador
    basePallet->SetId(iden);
}

void Pallet::devolverId(char*ide) {
    basePallet->GetId(ide);
}

void Pallet::imprimirDatos(ofstream& archOut) {
    basePallet->imprimirDatos(archOut);
}

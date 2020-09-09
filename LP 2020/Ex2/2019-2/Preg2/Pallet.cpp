/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pallet.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:35 PM
 */

#include "Pallet.h"

Pallet::Pallet() {
    id=NULL;
}

Pallet::Pallet(const Pallet& orig) {
    id=NULL;
}

Pallet::~Pallet() {
    if(id!=NULL)delete id;
}

void Pallet::SetId(const char* cad) {
    if (cad == NULL) return;
    if (id != NULL) delete id;
    id = new char[strlen(cad) + 1];
    strcpy(id, cad);
}

void Pallet::GetId(char* cad) const {
    if (id == NULL)
        return;
    strcpy(cad, id);
}


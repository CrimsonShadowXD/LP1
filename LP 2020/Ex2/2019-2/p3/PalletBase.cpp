/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletBase.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 11:08 PM
 */

#include "PalletBase.h"

PalletBase::PalletBase() {
    id=NULL;
}

PalletBase::PalletBase(const PalletBase& orig) {
}

PalletBase::~PalletBase() {
}

void PalletBase::SetId(const char *cad) {
    if (cad==NULL) return;
    if(id!=NULL) delete id;
    id = new char[strlen(cad)+1];
    strcpy(id,cad);
}

void PalletBase::GetId(char *cad) const {
    if(id==NULL)
        return;
    strcpy(cad,id);
}


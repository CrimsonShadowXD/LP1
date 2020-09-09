/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasePallet.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 09:21 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BasePallet.h"

BasePallet::BasePallet() {
    id=NULL;
}

BasePallet::~BasePallet() {
    if(id)delete id;
}

void BasePallet::GetId(char* ide) const {
    strcpy(ide,id);
}

void BasePallet::SetId(char* ide) {
    if(id)delete id;
    id=new char[strlen(ide)+1];
    strcpy(id,ide);
}

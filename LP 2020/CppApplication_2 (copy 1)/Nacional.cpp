 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nacional.cpp
 * Author: crimson
 * 
 * Created on July 3, 2020, 12:50 AM
 */

#include "Nacional.h"

Nacional::Nacional() {
    especialidad=NULL;
    facultad=NULL;
}

Nacional::Nacional(const Nacional& orig) {
}

Nacional::~Nacional() {
}

void Nacional::SetFacultad(char* cad) {
    if (cad==NULL) return;
    if(facultad!=NULL) delete facultad;
    facultad = new char[strlen(cad)+1];
    strcpy(facultad,cad);
}

void Nacional::GetFacultad(char* cad) const {
    if(facultad==NULL)
        return;
    strcpy(cad,facultad);
}

void Nacional::SetEspecialidad(char* cad) {
    if (cad==NULL) return;
    if(especialidad!=NULL) delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void Nacional::GetEspecialidad(char* cad) const {
    if(especialidad==NULL)
        return;
    strcpy(cad,especialidad);
}


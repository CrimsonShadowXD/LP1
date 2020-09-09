/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nacional.cpp
 * Author: cueva
 * 
 * Created on 1 de julio de 2020, 12:55 PM
 */

#include "Nacional.h"

Nacional::Nacional() {
}

Nacional::Nacional(const Nacional& orig) {
}

Nacional::~Nacional() {
}

void Nacional::SetFacultad(char* facultad) {
    this->facultad = facultad;
}

char* Nacional::GetFacultad() const {
    return facultad;
}

void Nacional::SetEspecialidad(char* especialidad) {
    this->especialidad = especialidad;
}

char* Nacional::GetEspecialidad() const {
    return especialidad;
}


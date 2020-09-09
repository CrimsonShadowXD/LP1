
/* 
 * File:   BaseAlum.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 6 de julio de 2020, 18:24
 */

#include <cstring>
#include "BaseAlum.h"
#include <fstream>

using namespace std;

BaseAlum::BaseAlum() {
    nombre = nullptr;
    codigo = 0;
}


BaseAlum::~BaseAlum() {
    if (nombre) delete [] nombre;
}

void BaseAlum::SetNombre(char* nombre) {
    
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
    
}

char* BaseAlum::GetNombre() const {
    char *salida = new char [strlen(this->nombre)+1];
    strcpy(salida,this->nombre);
    return salida;
}

void BaseAlum::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int BaseAlum::GetCodigo() const {
    return codigo;
}




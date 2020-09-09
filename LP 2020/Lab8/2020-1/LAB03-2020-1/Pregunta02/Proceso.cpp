
/* 
 * File:   Proceso.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 3 de julio de 2020, 09:49
 */

#include "Proceso.h"
#include <fstream>
#include <iostream>
#include "Miembro.h"
using namespace std;

Proceso::Proceso() {
}

Proceso::~Proceso(){
    
}

void Proceso::leemiembro(char *entrada){
        ifstream in(entrada,ios::in);
    if (!in){
        cout<<"Error abriendo miembros.csv."; exit(1);}
}
 void Proceso::imprimemiembro(char *entradaA, char *entradaP){
    mi.imprimir(entradaA,entradaP);    
 }

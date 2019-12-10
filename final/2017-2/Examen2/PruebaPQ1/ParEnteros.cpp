/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParEnteros.cpp
 * Author: alulab14
 * 
 * Created on 5 de diciembre de 2017, 09:48 AM
 */
//20150008 Daniela Cisneros
#include "ParEnteros.h"

ParEnteros::ParEnteros() {
    primer=0;
    segundo=0; 
}

ParEnteros::ParEnteros(const ParEnteros& orig) {
    primer=orig.primer;
    segundo=orig.segundo;
}

ParEnteros::~ParEnteros() {
}

void ParEnteros::SetSegundo(int segundo) {
    this->segundo = segundo;
}

int ParEnteros::GetSegundo() const {
    return segundo;
}

void ParEnteros::SetPrimer(int primer) {
    this->primer = primer;
}

int ParEnteros::GetPrimer() const {
    return primer;
}

bool ParEnteros::operator>(ParEnteros& p) {
    if(primer==p.primer) return 0;
    return primer<p.primer;

}

void ParEnteros::operator=(ParEnteros& orig) {
    primer=orig.primer;
    segundo=orig.segundo;
}

ostream& operator<<(ostream& arch, ParEnteros& p) {
    arch<<left<<"Primero: "<<setw(5)<<p.primer<<"Segundo: "<<p.segundo<<endl;
}

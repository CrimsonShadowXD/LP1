
/* 
 * File:   Curso.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 26 de junio de 2020, 08:02
 */
#include <cstring>
#include <fstream>
#include "Curso.h"

using namespace std;

Curso::Curso() {
    ccurso=nullptr;
}

Curso::Curso(const Curso& orig) {
    this->SetCcurso(orig.GetCcurso());
    this->SetCiclo(orig.GetCiclo());
    this->SetCredito(orig.GetCredito());
    this->SetNota(orig.GetNota());
            
}

Curso::~Curso() {
    //delete[] ccurso;
}

void Curso::SetCredito(float credito) {
    this->credito = credito;
}

float Curso::GetCredito() const {
    return credito;
}

void Curso::SetNota(int nota) {
    this->nota = nota;
}

int Curso::GetNota() const {
    return nota;
}

void Curso::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Curso::GetCiclo() const {
    return ciclo;
}

void Curso::SetCcurso(char* ccurso) {
    
    this->ccurso = new char [strlen(ccurso)+1];
    strcpy(this->ccurso,ccurso);
}

char* Curso::GetCcurso() const {
    char *aux=new char [strlen(this->ccurso)+1];
    strcpy(aux,this->ccurso);
    
    return aux;
}

void Curso::operator=(const Curso entrada){
    this->asignar(entrada);
}

void Curso::asignar(Curso orig){
    this->SetCcurso(orig.GetCcurso());
    this->SetCiclo(orig.GetCiclo());
    this->SetCredito(orig.GetCredito());
    this->SetNota(orig.GetNota());    
}

bool Curso::compare(const Curso &entrada){
    if (strcmp(this->GetCcurso(),entrada.GetCcurso()) != 0) return false;
    if (this->GetCiclo() != entrada.GetCiclo()) return false;
    
    return true;    
}
bool Curso::operator==(const Curso &entrada){
    return this->compare(entrada);    
}


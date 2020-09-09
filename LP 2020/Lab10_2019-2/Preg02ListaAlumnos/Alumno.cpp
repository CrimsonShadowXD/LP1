
/* 
 * File:   Alumno.cpp
 * Author: Rodrigo Agama
 * 
 * Created on 6 de julio de 2020, 19:29
 */

#include "Alumno.h"
#include "ListaNotas.h"
#include "AlIntercambio.h"
#include "AlRegular.h"

Alumno::Alumno() {
    elem = nullptr;
}


Alumno::~Alumno() {
    if (elem) delete elem;
    
}

 void Alumno::agregarNota(Nota &nuevo){
     this->notas.agregarNota(nuevo);
 }
    void Alumno::imprimir(ofstream &out){
        this->elem->imprimir(out);
        this->notas.imprimirLista(out);
    }
    void Alumno::leer(ifstream &in){
        char tipo;
        in>>tipo; if (in.eof()) return;
        in.get();
        
        if (tipo=='I') elem = new AlIntercambio;
        else if (tipo=='R') elem = new AlRegular;
        
        elem->leer(in);
    }
    
     int Alumno::getCodigo(){
        return this->elem->GetCodigo();
    }


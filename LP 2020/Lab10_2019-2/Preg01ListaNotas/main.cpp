
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama
 *
 * Created on 5 de julio de 2020, 14:45
 */
#include <iostream>
#include <cstdlib>
#include "ListaNotas.h"
#include "Nota.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaNotas prueba;
    Nota elem1,elem2;
    elem1.SetNota(18);
    elem2.SetNota(16);
    elem1.SetCodigo("INF144");
    elem2.SetCodigo("IEE286");
    elem1.SetSemestre("2020-1");
    elem2.SetSemestre("2020-1");
    
    prueba.agregarNota(elem1);
    prueba.agregarNota(elem2);
    
    ofstream out("Prueba Notas.txt",ios::out);
    if (!out) {cout<<"Error creando la prueba de notas."<<endl; exit(1);}
    
    prueba.imprimirLista(out);
    

    return 0;
}


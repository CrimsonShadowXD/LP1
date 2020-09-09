/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 7, 2020, 4:28 AM
 */

#include "ListaNotas.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaNotas prueba;
    ifstream arch("Cursos.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba.leer(arch);
    ofstream archi("Prueba.txt",ios::out);
    if(!archi){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba.imprimir(archi);
    return 0;
}


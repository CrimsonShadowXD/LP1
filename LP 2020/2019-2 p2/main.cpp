/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 7, 2020, 5:08 AM
 */

#include "ListaNotas.h"
#include "ListaAlumnos.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    ListaNotas prueba;
//    ifstream arch("Cursos.csv",ios::in);
//    if(!arch){
//        cout << "No se puede abrir";
//        exit(1);
//    }
//    prueba.leer(arch);
//    ofstream archi("Prueba.txt",ios::out);
//    if(!archi){
//        cout << "No se puede abrir";
//        exit(1);
//    }
//    prueba.imprimir(archi);
    
    ListaAlumnos prueba2;
    ifstream arch2("Alumnos.csv",ios::in);
    if(!arch2){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba2.crear(arch2);
    ofstream arch3("Prueba2.txt",ios::out);
    if(!arch3){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba2.imprime(arch3);
    
    return 0;
}


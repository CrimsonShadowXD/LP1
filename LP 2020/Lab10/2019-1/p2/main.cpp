/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 9, 2020, 8:24 PM
 */

#include "ListaMiembros.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch("Universidad.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }
    ListaMiembros prueba;
    prueba.crear(arch);
    ofstream archi("Rep.txt",ios::out);
    if(!archi){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba.imp(archi);
    prueba.mod(0.23);
    ofstream arch2("Rep2.txt",ios::out);
    if(!arch2){
        cout << "No se puede abrir";
        exit(1);
    }
    prueba.imp(arch2);
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 8, 2020, 10:18 PM
 */

#include "ListaPallets.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch("pallets.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }
    ofstream archi("r.txt",ios::out);
    if(!archi){
        cout << "No se puede abrir";
        exit(1);
    }
    ListaPallets prueba;
    prueba.crear(arch);
    prueba.imprime(archi);
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2019, 11:50 AM
 */

#include "a.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista=NULL;
    crearlista(lista,leeRegistros,compararReg);
    imprimelista(lista,imprime);
    
    return 0;
}


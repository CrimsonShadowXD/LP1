/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: La Rosa
 *
 * Created on 12 de octubre de 2019, 19:58
 */

#include "Func-Ex-Preg01.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *asientos;
    char ***rutas;
    leerRutas(rutas,asientos);
    imprimirRutas(rutas,asientos);
    return 0;
}


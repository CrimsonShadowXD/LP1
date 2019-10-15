/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: La Rosa
 *
 * Created on 14 de octubre de 2019, 19:57
 */

#include "Func-Ex-Preg04.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *extracciones;int N;
    leerExtracciones(extracciones,N);
    imprimirExtracciones(extracciones,N);
    return 0;
}


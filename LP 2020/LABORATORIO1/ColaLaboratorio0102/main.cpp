/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 19 de junio de 2020, 09:34 AM
 */
#include "BibliotecaColaGenerica.h"
#include "Funcioneslaboratorio01.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *cola;
    creaCola(cola,leenumero);
    atiendeCola(cola,imprimenumero);
    return 0;
}

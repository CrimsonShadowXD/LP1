/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 3, 2020, 12:37 AM
 */

#include "contenedor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    contenedor prueba;
    int n_Int=0, n_Nac=0, cap_Nac=0, cap_Int=0;
    prueba.lee(n_Int,n_Nac,cap_Nac,cap_Int);
    prueba.imprimeInt(n_Int);
    prueba.imprimeNac(n_Nac);
    return 0;
}


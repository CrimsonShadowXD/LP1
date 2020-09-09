/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 2 de junio de 2020, 08:13 AM
 */

#include "FuncionesEx01_20201_Preg01.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cursos, **profesores;
    int *codProfesores;
    leerDatos(cursos,codProfesores,profesores);
    imprimirDatos(cursos,codProfesores,profesores);
    return 0;
}


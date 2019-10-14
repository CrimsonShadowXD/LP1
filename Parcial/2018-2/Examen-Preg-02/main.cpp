/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: La Rosa
 *
 * Created on 13 de octubre de 2019, 18:41
 */

#include "Func-Ex-Preg01.h"
#include "Func-Ex-Preg02.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *asientos;
    char ***rutas,****pasajeros,***sinAsignar;
    leerRutas(rutas,asientos);
    imprimirRutas(rutas,asientos);
    ubicarPasajeros(rutas,asientos,pasajeros,sinAsignar);
    reporteDeViajes(rutas,asientos,pasajeros,sinAsignar);
    return 0;
}

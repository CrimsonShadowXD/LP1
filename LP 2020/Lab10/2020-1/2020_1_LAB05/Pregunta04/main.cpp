/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 09:07 AM
 */

#include "Reserva.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Reserva reserva;
    reserva.carga("Aulas.csv","Miembros.csv");
    reserva.asigna(4);
    reserva.imprimirAulas();
    return 0;
}


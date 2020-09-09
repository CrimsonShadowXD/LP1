/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:40 AM
 */

#include "Cuentas.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cuentas banco;
    banco.leerCuentas("Clientes.csv");
    banco.leerTiposDeCambio("TipoDeCambio.csv");
    banco.reporteDeCuentas("ReporteDeCuentasLinux.txt");
    return 0;
}


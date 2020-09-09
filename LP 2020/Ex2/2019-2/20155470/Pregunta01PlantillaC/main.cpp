/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 08:03 AM
 */

#include <cstdlib>

#include "Cliente.h"
#include "PlCola.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Prueba.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    class Prueba prueba;
    
    ifstream archClientes("Banco-Clientes.csv",ios::in);
    if(!archClientes){
        cout<<"No se ha encontrado el archivo de clientes"<<endl;
        exit(1);
    }
    ofstream archReporte("reporte.txt",ios::out);
    if(!archReporte){
        cout<<"No se ha encontrado el archivo de reporte"<<endl;
        exit(1);
    }
    
    //cabecera
    prueba.imprimirCabeceras(archReporte,archClientes);
    //leer Datos y llenar la cola
    prueba.leerClientes(archClientes);
    //impirmir cabeceras y Reporte
    prueba.imprimirClientes(archReporte);
    cout<<"exito"<<endl;
    return 0;
}


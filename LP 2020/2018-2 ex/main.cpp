/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 4, 2020, 4:23 PM
 */

#include "ListaConductores.h"
#include "Infracciones.h"
#include "ListaDoble.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cerr<<"error";
        exit(1);
    }
    ListaConductores prueba;
    prueba.crear(arch);
    ofstream out("reporte.txt",ios::out);
    prueba.imprimir(out);
    ifstream arch2("Registro_de_Faltas.csv",ios::in);
    if(!arch2){
        cerr<<"error";
        exit(1);
    }
    prueba.cargarinfracciones(arch2);
    ofstream out2("reporte2.txt",ios::out);
    prueba.imprimir(out2);
    
    
    
    ifstream arch3("Infracciones.csv",ios::in);
    if(!arch3){
        cerr<<"error";
        exit(1);
    }
    ListaDoble<Infracciones> prueba100;
    prueba100.leer(arch3);
    ofstream out3("reporte3.txt",ios::out);
    ofstream out4("reporte4.txt",ios::out);
    prueba100.imprimir(out3,0);
    prueba100.imprimir(out4,1);
    
    return 0;
}


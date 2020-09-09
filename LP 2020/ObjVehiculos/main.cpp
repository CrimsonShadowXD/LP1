/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 24 de junio de 2020, 11:26 AM
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Conductor.h"
#include "Faltas.h"
#include "sobrecarga.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Faltas f1,faux;
    Conductor c1,lc1[200];
    int i,cant=0;
    
    f1.SetCodigo(50);
    f1.SetDni(9942265);
    f1.SetMulta(100.00);
    
    c1.SetBrevete(99991111);
    c1.SetDni(9942265);
    c1.SetNombre("Rony Cueva");
    c1.insfaltas(f1);
    c1+f1;

    // Leer del archivo conductor y cargar arreglo de obj
    // Leer del archivo faltas e insertar las faltas al conductor
    // Finalmente imprimir cada conductor la cant de faltas y monto de multa
    // La siguiente parte debe estar en funciones que son invocadas desde el main
    ////////////////Leer archivo conductores
    ifstream archc("Conductores.csv",ios::in);
    if(!archc){
        cout << "No se puede abrir";
        exit(1);
    }
    while(1){
        archc >> lc1[cant];
        if(archc.eof()) break;
        cant++;
    }
    ////////////////////////////////////////////////7777777
    ifstream arch("Rfaltas.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }
    while(1){
        arch >> faux;
        if(arch.eof()) break;
        for(int i=0;i<cant;i++)
            if(lc1[i].GetDni()==faux.GetDni()){
                lc1[i]+faux;
                break;
            }
    }
    
    ////////////////////////////////////////////////7777777
    ofstream archo("reporte.txt",ios::out);
    if(!archo){
        cout << "No se puede abrir";
        exit(1);
    }
    //Conductor Nombre Brevete
    //Cantidad de multas y Monto de las multas        
    for(int i=0;i<cant;i++)
        archo << lc1[i];
    
    
    return 0;
}


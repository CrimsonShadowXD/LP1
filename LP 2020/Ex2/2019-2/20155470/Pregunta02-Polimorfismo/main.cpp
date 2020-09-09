/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 09:20 AM
 */

#include <cstdlib>
#include <cstring>

#include "BasePallet.h"
#include "PalletUS.h"
#include "PalletEU.h"
#include "PalletPE.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    BasePallet *arregloPallets[200];
    ifstream archPallets("pallets.csv",ios::in);
    if(!archPallets){
        cout<<"No se ha encontrado el archivo de pallets"<<endl;
        exit(1);
    }
    ofstream archReporte("report.txt",ios::out);
    if(!archReporte){
        cout<<"No se ha encontrado el archivo de reporte"<<endl;
        exit(1);
    }
    
    
    char tipo[100],iden[100];
    int numeroPallets=0;
    while(1){
        archPallets.getline(tipo,100,',');
        if(archPallets.eof())break;
        if(strcmp(tipo,"US")==0){
            arregloPallets[numeroPallets]=new PalletUS;
        }else if(strcmp(tipo,"EU")==0){
            arregloPallets[numeroPallets]=new PalletEU;
        }else if(strcmp(tipo,"PE")==0){
            arregloPallets[numeroPallets]=new PalletPE;
        }
        archPallets.getline(iden,100);
        //leemos el identificador
        arregloPallets[numeroPallets]->SetId(iden);
        numeroPallets++;
    }
    
    archReporte<<left<<setw(15)<<"IDENTIFICADOR"<<setw(15)<<"CAPACIDAD"<<setw(15)<<"TIPO"<<endl;
    for (int i = 0; i < numeroPallets; i++) {
        arregloPallets[i]->imprimirDatos(archReporte);
    }

    cout<<"exito"<<endl;
    return 0;
}


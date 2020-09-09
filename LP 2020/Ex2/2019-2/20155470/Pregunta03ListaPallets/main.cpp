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
#include "ListaPallets.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
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
    
    
    ListaPallets lp;
    lp.leerPallets(archPallets);
    lp.imprimirPallets(archReporte);

    cout<<"exito"<<endl;
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPallets.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:03 AM
 */
#include <fstream>

#include "NodoPallet.h"
using namespace std;
#ifndef LISTAPALLETS_H
#define LISTAPALLETS_H

class ListaPallets {
public:
    ListaPallets();
    virtual ~ListaPallets();
    
    void leerPallets(ifstream&);
    void insertarPallet(char*,ifstream&);
    void imprimirPallets(ofstream&);
    
private:
    NodoPallet *listaPallets;
};  

#endif /* LISTAPALLETS_H */


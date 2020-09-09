/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pallet.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 09:59 AM
 */
#include <fstream>

#include "BasePallet.h"
using namespace std;
#ifndef PALLET_H
#define PALLET_H

class Pallet {
public:
    Pallet();
    virtual ~Pallet();
    
    void definirTipo(char*);
    void leerDatos(ifstream&);
    void devolverId(char*);
    void imprimirDatos(ofstream&archOut);
private:
    BasePallet *basePallet;
};

#endif /* PALLET_H */


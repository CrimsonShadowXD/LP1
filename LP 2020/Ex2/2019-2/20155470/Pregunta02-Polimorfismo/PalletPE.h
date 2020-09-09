/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletPE.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 09:23 AM
 */
#include <fstream>

#include "BasePallet.h"
using namespace std;
#ifndef PALLETPE_H
#define PALLETPE_H

class PalletPE:public BasePallet {
public:
    void leerDatos(ifstream&) override;
    void imprimirDatos(ofstream&) override;
    char devolverTipo() override;

private:
    double capacidad=60;
};

#endif /* PALLETPE_H */


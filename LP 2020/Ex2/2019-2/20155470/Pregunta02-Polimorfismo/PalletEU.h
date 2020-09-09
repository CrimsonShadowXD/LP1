/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletEU.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 09:23 AM
 */
#include <fstream>

#include "BasePallet.h"
using namespace std;
#ifndef PALLETEU_H
#define PALLETEU_H

class PalletEU:public BasePallet {
public:
//    PalletEU();
//    virtual ~PalletEU();
////    void SetTipo(char* t);
////    void GetTipo(char* t) const;
//    void SetCapacidad(double capacidad);
//    double GetCapacidad() const;
//    
//    void leerDatos(ifstream&) override;
//    void imprimirDatos(ofstream&) override;
    void leerDatos(ifstream&) override;
    void imprimirDatos(ofstream&) override;
    char devolverTipo() override;
private:
    double capacidad=40;
//    char* tipo;
};

#endif /* PALLETEU_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuentas.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:55 AM
 */

#ifndef CUENTAS_H
#define CUENTAS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <map>
#include <iterator>
#include "ArbolBBG.h"
#include "Cuenta.h"
#include "Moneda.h"

using namespace std;

class Cuentas {
private:
    class ArbolBBG<class Cuenta> arbCuentas;
    map<char,class Moneda> monedas;
public:
    Cuentas();
    Cuentas(const Cuentas& orig);
    virtual ~Cuentas();
    
    void leerCuentas(const char*);
    void leerTiposDeCambio(const char*);
    void ejecutarMovimientos( );
    void reporteDeCuentas(const char*);
    
    void leerTransacciones(ifstream&);
    void impLinea(ofstream&,char c);
    void impCabecera(ofstream&);
    void modificarSaldo(int,char,double,char);
};

#endif /* CUENTAS_H */


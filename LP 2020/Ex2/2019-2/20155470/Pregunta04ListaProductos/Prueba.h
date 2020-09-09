/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prueba.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 09:12 AM
 */
#include <fstream>

#include "PlCola.h"
#include "Cliente.h"
using namespace std;
#ifndef PRUEBA_H
#define PRUEBA_H

class Prueba {
public:
    void imprimirCabeceras(ofstream&archOut,ifstream&archIn);
    void leerClientes(ifstream&archIn);
    void imprimirClientes(ofstream&archOut);
    void imprimirLineas(ofstream&archOut,char c,int n);
private:
    PlCola<Cliente> clientes;
};

#endif /* PRUEBA_H */


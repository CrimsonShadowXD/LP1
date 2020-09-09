/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faltante.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 10:30 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Faltante.h"

void Faltante::SetCantidadFaltante(double cantidadFaltante) {
    this->cantidadFaltante = cantidadFaltante;
}

double Faltante::GetCantidadFaltante() const {
    return cantidadFaltante;
}

void Faltante::SetCodigoPedido(int codigoPedido) {
    this->codigoPedido = codigoPedido;
}

int Faltante::GetCodigoPedido() const {
    return codigoPedido;
}

void Faltante::operator=(Faltante& fal) {
    codigoPedido=fal.codigoPedido;
    cantidadFaltante=fal.codigoPedido;
}


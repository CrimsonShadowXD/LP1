/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 10:27 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
}


void Pedido::SetCantidad(double cantidad) {
    this->cantidad = cantidad;
}

double Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::operator=(Pedido& ped) {
    codigo=ped.codigo;
    cantidad=ped.cantidad;
}



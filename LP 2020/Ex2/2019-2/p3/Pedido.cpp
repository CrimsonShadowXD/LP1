/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: crimson
 * 
 * Created on July 14, 2020, 1:16 PM
 */

#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetCantkg(double cantkg) {
    this->cantkg = cantkg;
}

double Pedido::GetCantkg() const {
    return cantkg;
}

void Pedido::SetPedido(int pedido) {
    this->pedido = pedido;
}

int Pedido::GetPedido() const {
    return pedido;
}

void Pedido::operator=(const Pedido&p){
    SetCantkg(p.GetCantkg());
    SetPedido(p.GetPedido());
}

ofstream& operator<<(ofstream&out, Pedido&p){
    out<<p.GetPedido()<<' '<<p.GetCantkg()<<"kg"<<endl;
    return out;
}

void operator>>(ifstream&in, Pedido&p){
    int cod;
    double kg;
    in>>cod;p.SetPedido(cod);
    in.get();
    in>>kg;p.SetCantkg(kg);
    in>>ws;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 14, 2020, 1:00 PM
 */

#include "ListaProducto.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaProducto p;
    ifstream arch("producto.csv",ios::in);
    if(!arch){
        cerr<<"error"<<endl;
        exit(1);
    }
    ifstream in("stock.csv",ios::in);
    if(!in){
        cerr<<"error"<<endl;
        exit(1);
    }
    ifstream p1("pedido.csv",ios::in);
    if(!p1){
        cerr<<"error"<<endl;
        exit(1);
    }
    ofstream cod("cod.txt",ios::out);
    if(!cod){
        cerr<<"error"<<endl;
        exit(1);
    }
    ofstream todo("todo.txt",ios::out);
    if(!todo){
        cerr<<"error"<<endl;
        exit(1);
    }
    ofstream ped("pedidos.txt",ios::out);
    if(!ped){
        cerr<<"error"<<endl;
        exit(1);
    }
    p.crear(arch);
    p.impPcod(cod);
    p.llenarPallet(in);
    p.impLP(todo);
    p.leerPedidos(p1);
    p.impCPed(ped);
    p.atenderPedidos();
    return 0;
}


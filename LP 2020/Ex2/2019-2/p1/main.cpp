/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 8, 2020, 8:44 PM
 */


#include "PlCola.h"
#include "Cliente.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    PlCola<int>diez;
//    diez.crear("a.txt");
//    int a=diez.Pop();
//    cout<<a<<endl;
//    diez.imprimir("b.txt");
    ifstream arch("Banco-Clientes.csv",ios::in);
    if(!arch){
        cerr<<"error"<<endl;
        exit(1);
    }
    ofstream arch2("rar.txt",ios::out);
    PlCola<Cliente> m;
    int hi,mi,si;
    char s;
    arch>>hi>>s>>mi>>s>>si;
    arch>>ws;
    arch2<<hi<<' '<<mi<<' '<<si<<endl;
    m.crear(arch);
    m.imprimir(arch2);
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:51 AM
 */

#include "Aula.h"
#include <vector>
#include <iterator>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in("Aulas.csv", ios::in);
    if (!in) {
        cout << "No se puede abrir Aulas" << endl;
        exit(1);
    }
    ofstream out("pruebaaulas.txt", ios::out);
    if (!out) {
        cout << "No se puede abrir" << endl;
        exit(1);
    }
    vector <Aula> aulas;
    Aula auxA;
    while(1){
        if(in.eof())break;
        in>>auxA;
        aulas.push_back(auxA);
    }
    out<<"Clave"<<setw(10)<<"capacidad"<<endl;
    vector<Aula>::iterator it;
    for (it = aulas.begin(); it != aulas.end(); it++) {
        out << *it;
    }
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#include <fstream>
#include <iterator>
#include <list>

using namespace std;

#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo {
public:
    Vehiculo();
    
    void setPlaca(char *entrada);
    char* getPlaca();    
    
    void leer(ifstream &in);
    void imprimir(ofstream &out);
    
    void multar(int codigo);
    int* obtenerMultas();
    
    bool operator>(Vehiculo orig);
private:
    char *placa;
    list<int> infracciones;
};

#endif /* VEHICULO_H */


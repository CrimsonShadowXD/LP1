/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Nombre: Leandro Lazo La Rosa
 * Codigo: 20130263
 *
 * Created on 10 de diciembre de 2019, 08:43 AM
 */

#ifndef CLASEHORARIOS_H
#define CLASEHORARIOS_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;


class Horarios{
public:
    Horarios();
    void leer(char*);
    void mostrar(char*);
private:
    int hora;
    int min;
    int seg;
    class PlCola<int>DNI;
    class PlCola<char*>pasajeros;
    class PlCola<int>Llegada;
    class PlCola<float>Espera;
    class PlCola<int>Salida;
    int TEsperaTotal;
    int CantPasajeros;
};



#endif /* CLASEHORARIOS_H */


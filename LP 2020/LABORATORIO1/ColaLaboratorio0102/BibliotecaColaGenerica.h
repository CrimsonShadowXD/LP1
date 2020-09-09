/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaColaGenerica.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 19 de junio de 2020, 08:05 AM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

bool colaVacia(void *cola);
void encolarDato(void *&colaInicio,void *&colaFin,void *dato);
void encola(void *&cola,void *dato);
void creaCola(void *&cola,void *(*lee)(ifstream&));
void *desencolarDato(void *&colaInicio,void *&colaFin);
void *desencola(void *&cola);
void atiendeCola(void *&cola,void (*imprime)(void*,ofstream&));

#endif /* BIBLIOTECACOLAGENERICA_H */


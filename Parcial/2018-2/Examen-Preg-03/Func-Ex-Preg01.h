/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Func-Ex-Preg01.h
 * Author: La Rosa
 *
 * Created on 13 de octubre de 2019, 18:44
 */

#ifndef FUNC_EX_PREG01_H
#define FUNC_EX_PREG01_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
#include <fstream>

using namespace std;

char **ObtenerCliente(ifstream& arch);
int obtenerAsientos(ifstream& arch);
void incrementarRutas(char **&rutas,int *&asientos,int &n, int &cap);

void leerRutas(char ***&rutas,int *&asientos);

void imprimirRuta(ofstream& arch,char **ruta,int asiento);
void imprimirRutas(char ***rutas,int *asientos);


#endif /* FUNC_EX_PREG01_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 11 de octubre de 2019, 08:09 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

void *leerCadena(ifstream& arch);

void incrementar(void **&reg,int &n,int &cap);

void leerPalets(void *&palets);

void imprimirPalet(ofstream& arch,void *palets);

void ImprimirPalets(void *palets);

void *leerProd(ifstream& arch);

void leerProductos(void *&producto);

void imprimirProd(ofstream& arch,void *prod);

void imprimirProductos(void *producto);

int comparar(void *i,void *j);

void cambio(void *&i,void *&j);

void QuickS(void *&producto,int ini, int fin);

void ordenarproductos(void *&producto);

void rayado(ofstream& arch,char d);

void imprimirCabecera(ofstream& arch);

int Verificar(void *Prod,void *Palet);

void imprimCantProd(ofstream& arch,void *prod,int CantProd);

void cargastock(void *&palets,void *&producto);



#endif /* FUNCIONES_H */


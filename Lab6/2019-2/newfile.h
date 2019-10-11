/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newfile.h
 * Author: alulab14
 *
 * Created on 9 de octubre de 2019, 05:17 PM
 */

#ifndef NEWFILE_H
#define NEWFILE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

void leerPalets(void *&almacenes,int &N);
void imprimirPalets(void *almacenes,int N);
void leerProductos(void *&codigoProd,void *&nombreProd,int &N);
void imprimirProductos(void *codigoProd,void *nombreProd,int N);
void ordenarproductos(void *&codigoProd,void *&nombreProd,int N);
void cuentaproductos(void *almacenes,void *codigoProd,void *nombreProd,int N);


#endif /* NEWFILE_H */


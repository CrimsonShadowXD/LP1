/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funcioneslaboratorio05.h
 * Author: La Rosa
 *
 * Created on 7 de octubre de 2019, 20:41
 */

#ifndef FUNCIONESLABORATORIO05_H
#define FUNCIONESLABORATORIO05_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void leerArchivo(char **&lAlm,char **&lProd,char **&lPalet);
void leerPalets(char ***&almacenes);
void imprimirPalets(char ***almacenes);
void leerProductos(char **&codigoProd,char **&nombreProd);
void imprimirProductos(char **codigoProd,char **nombreProd);
void ordenarproductos(char **&codigoProd,char **&nombreProd);
void cuentaproductos(char ***almacenes,char **codigoProd,char **nombreProd);

#endif /* FUNCIONESLABORATORIO05_H */


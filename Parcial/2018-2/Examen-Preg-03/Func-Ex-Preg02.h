/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Func-Ex-Preg02.h
 * Author: La Rosa
 *
 * Created on 13 de octubre de 2019, 18:46
 */

#ifndef FUNC_EX_PREG02_H
#define FUNC_EX_PREG02_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
#include <fstream>

using namespace std;

//Llega hasta la segunda parte del reporte
void saltarLineas(ifstream& arch,int &n);
//funcion para leer un pasajero
char **leerPasajeros(ifstream& arch);
//Funciones para asignar al pasajero
void buscarDest(char **ruta,char **aux,int &encontrado);
void BuscarCarro(char ***rutas,int *asientos,char **aux,int &posActual);
int contarPasajeros(char ***pasajeros);
void colocarPasajero(char ***&pasajeros,char **aux);
void incrementarSA(char ***&sinAsignar,int &n,int &cap);
void colocarSinAsignar(char **aux,char ***&sinAsignar,int &n,int &cap);
void ubicarPasajeros(char ***rutas,int *asientos,char ****&pasajeros,char ***&sinAsignar);
//funciones para imprimir pasajero
void imprRuta(ofstream& arch,char **ruta,int &n);
void impPasDestino(ofstream& arch,char *Destino,char **pasajeros,int &n);
void imprPasaj(ofstream& arch,char **ruta,char ***pasajeros,int auxPos);
void imprimrSA(ofstream& arch,char **sinAsignar);
void reporteDeViajes(char ***rutas,int *asientos,char ****pasajeros,char ***sinAsignar);

#endif /* FUNC_EX_PREG02_H */


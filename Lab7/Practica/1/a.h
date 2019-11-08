/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   a.h
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2019, 11:50 AM
 */

#ifndef A_H
#define A_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void *leeRegistros(ifstream& arch);

int compararReg(void *elem,void *dato);

void insertarlista(void *&lista,void *dato,int(*comp)(void*,void*));

void crearlista(void *&lista,void*(*lee)(ifstream&),int (*comp)(void*,void*));

void imprime(void *reg,ofstream& arch);

void imprimelista(void*lista,void(*imprime)(void*,ofstream&));

void eliminaReg(void *d);

void eliminalista(void *lista,void(*elimina)(void*));

void crearPila(void *&lista,void *&dep);

#endif /* A_H */


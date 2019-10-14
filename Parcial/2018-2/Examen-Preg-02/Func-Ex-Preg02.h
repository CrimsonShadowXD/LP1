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

void ubicarPasajeros(char ***rutas,int *asientos,char ****&pasajeros,char ***&sinAsignar);
void reporteDeViajes(char ***rutas,int *asientos,char ****pasajeros,char ***sinAsignar);

#endif /* FUNC_EX_PREG02_H */


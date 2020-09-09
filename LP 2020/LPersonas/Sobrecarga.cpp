/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sobrecarga.cpp
 * Author: cueva
 * 
 * Created on 8 de julio de 2020, 01:31 PM
 */

#include <iostream>
#include <fstream>
#include "Npersona.h"
#include "Profesor.h"
#include "Alumno.h"
#include "Sobrecarga.h"

using namespace std;

ofstream &operator << (ofstream &arch, Persona *&c){
    c->imprime(arch);
}

ifstream &operator >> (ifstream &arch, Persona *&c){
    c->lee(arch);
}


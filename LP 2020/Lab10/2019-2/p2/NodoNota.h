/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoNota.h
 * Author: crimson
 *
 * Created on July 7, 2020, 4:31 AM
 */

#ifndef NODONOTA_H
#define NODONOTA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Nota.h"
#include "ListaNotas.h"

using namespace std;

class NodoNota {
private:
    class Nota nota;
    class NodoNota *sig;
public:
    NodoNota();
    NodoNota(const NodoNota& orig);
    virtual ~NodoNota();

    friend class ListaNotas;
};

#endif /* NODONOTA_H */


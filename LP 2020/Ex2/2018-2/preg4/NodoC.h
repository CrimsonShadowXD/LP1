/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoC.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:53 AM
 */

#ifndef NODOC_H
#define NODOC_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Conductor.h"
#include "ListaConductores.h"
using namespace std;

class NodoC {
private:
    class Conductor elem;
    class NodoC *sig;
    class NodoC *ant;
public:
    NodoC();
    friend class ListaConductores;
};

#endif /* NODOC_H */


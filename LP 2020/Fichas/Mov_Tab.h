/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mov_Tab.h
 * Author: crimson
 *
 * Created on July 4, 2020, 10:22 PM
 */

#ifndef MOV_TAB_H
#define MOV_TAB_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Tablero.h"
using namespace std;

class Mov_Tab {
private:
    Tablero tabla;
public:
    Mov_Tab();
    Mov_Tab(const Mov_Tab& orig);
    virtual ~Mov_Tab();

    void cargaymover();
};

#endif /* MOV_TAB_H */


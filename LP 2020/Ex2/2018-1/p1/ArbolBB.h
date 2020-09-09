/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBB.h
 * Author: crimson
 *
 * Created on July 13, 2020, 1:20 AM
 */

#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Nodo.h"

using namespace std;

class ArbolBB {
private:
    class Nodo *elem;
public:
    ArbolBB();
    ArbolBB(const ArbolBB& orig);
    virtual ~ArbolBB();

};

#endif /* ARBOLBB_H */


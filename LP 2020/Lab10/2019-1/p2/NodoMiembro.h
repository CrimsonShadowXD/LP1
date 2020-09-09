/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoMiembro.h
 * Author: crimson
 *
 * Created on July 9, 2020, 8:24 PM
 */

#ifndef NODOMIEMBRO_H
#define NODOMIEMBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "ListaMiembros.h"
#include "Miembro.h"

using namespace std;

class NodoMiembro {
private:
    class Miembro *elem;
    class NodoMiembro *sig;
    
    
public:
    NodoMiembro();
    NodoMiembro(const NodoMiembro& orig);
    virtual ~NodoMiembro();
    friend class ListaMiembros;
};

#endif /* NODOMIEMBRO_H */


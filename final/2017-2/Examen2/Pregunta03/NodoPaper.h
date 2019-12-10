/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPaper.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 10:24 AM
 */
//20150008 Daniela Cisneros
#ifndef NODOPAPER_H
#define NODOPAPER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaPaper.h"
using namespace std;

class NodoPaper {
public:
    NodoPaper();
    NodoPaper(const NodoPaper& orig);
    virtual ~NodoPaper();
    friend class ListaPaper;
private:
    Paper* dato;
    class NodoPaper * sig;

};

#endif /* NODOPAPER_H */


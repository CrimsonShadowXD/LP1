/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Npdp.h
 * Author: crimson
 *
 * Created on July 10, 2020, 6:35 AM
 */

#ifndef NPDP_H
#define NPDP_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Miembro.h"
#include "Lista.h"

using namespace std;

class Npdp {
private:
    class Miembro *elem;
    class Npdp *sig;
public:
    Npdp();
    Npdp(const Npdp& orig);
    virtual ~Npdp();
    friend class Lista;
};

#endif /* NPDP_H */


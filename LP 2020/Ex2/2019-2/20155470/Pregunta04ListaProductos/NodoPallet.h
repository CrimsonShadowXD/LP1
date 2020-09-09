/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPallet.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:02 AM
 */
#include <fstream>

#include "Pallet.h"
using namespace std;
#ifndef NODOPALLET_H
#define NODOPALLET_H

class NodoPallet {
public:
    NodoPallet();
    friend class ListaPallets;
private:
    NodoPallet *sig;
    Pallet pallet;
};

#endif /* NODOPALLET_H */


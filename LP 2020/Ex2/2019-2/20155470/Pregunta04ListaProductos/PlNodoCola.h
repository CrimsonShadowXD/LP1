/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlNodoCola.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 08:08 AM
 */

#ifndef PLNODOCOLA_H
#define PLNODOCOLA_H
#include <fstream>
#include <cstdlib>
using namespace std;


template <typename T> class PlCola;
template <typename T> 
class PlNodoCola {
public:
    PlNodoCola(){
        sig=NULL;
    };
    friend class PlCola<T>;
    
private:
    T dato;
    PlNodoCola<T> *sig;
};

#endif /* PLNODOCOLA_H */


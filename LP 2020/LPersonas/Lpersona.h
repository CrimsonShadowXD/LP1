/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lpersona.h
 * Author: cueva
 *
 * Created on 7 de julio de 2020, 11:19 AM
 */

#ifndef LPERSONA_H
#define LPERSONA_H
#include <fstream>
#include "Npersona.h"

using namespace std;
class Lpersona{
    private:
        Npersona *lpers;
        
    public:
        Lpersona();
        void lee(char*);
        void inserta(Persona *&);
        void imprime(char*);
        void busca(int, char*);
};
    

#endif /* LPERSONA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParEnteros.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 09:48 AM
 */
//20150008 Daniela Cisneros
#ifndef PARENTEROS_H
#define PARENTEROS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class ParEnteros {
public:
    ParEnteros();
    ParEnteros(const ParEnteros& orig);
    virtual ~ParEnteros();
    void SetSegundo(int segundo);
    int GetSegundo() const;
    void SetPrimer(int primer);
    int GetPrimer() const;
    bool operator >(ParEnteros&);
    void operator =(ParEnteros&);
    friend ostream & operator<<(ostream&, ParEnteros &);
private:
    int primer;
    int segundo;
};

#endif /* PARENTEROS_H */


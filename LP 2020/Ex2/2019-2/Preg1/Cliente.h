/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: crimson
 *
 * Created on July 20, 2020, 10:56 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Cliente {
private:
    int dni,horallegada;
    char *nombre;
    double tiempo;
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTiempo(double tiempo);
    double GetTiempo() const;
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetHorallegada(int horallegada);
    int GetHorallegada() const;
    void SetDni(int dni);
    int GetDni() const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    
    void operator=(const Cliente& );
    bool operator==(const Cliente&);
    bool operator>(const Cliente&);
    bool operator<(const Cliente&);

};
ofstream& operator<<(ofstream&, Cliente&);
void operator>>(ifstream&, Cliente&);
#endif /* CLIENTE_H */


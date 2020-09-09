/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuenta.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:43 AM
 */

#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Cuenta {
private:
    int codigo;
    char *cliente,*estado;
    double saldo;
public:
    Cuenta();
    Cuenta(const Cuenta& orig);
    virtual ~Cuenta();
    void SetSaldo(double saldo);
    double GetSaldo() const;
    void SetEstado(const char*  );
    void GetEstado(char*) const;
    void SetCliente(const char*  );
    void GetCliente(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    
    void operator=(const Cuenta&);
    bool operator==(const Cuenta&);
    bool operator>(const Cuenta&);
    bool operator<(const Cuenta&);
};
ofstream& operator<<(ofstream&, Cuenta&);
void operator>>(ifstream&, Cuenta&);

#endif /* CUENTA_H */


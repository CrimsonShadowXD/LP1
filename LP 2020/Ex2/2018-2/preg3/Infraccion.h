/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:26 AM
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Infraccion {
private:
    int codigo;
    char *descripcion,*gravedad;
    double monto;
public:
    Infraccion();
    Infraccion(const Infraccion& orig);
    virtual ~Infraccion();
    void SetMonto(double monto);
    double GetMonto() const;
    void SetGravedad(const char*  );
    void GetGravedad(char*) const;
    void SetDescripcion(const char*    );
    void GetDescripcion(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    
    void operator=(const Infraccion&cli);
    bool operator==(int);
    bool operator==(const Infraccion&);
    bool operator>(const Infraccion&);
    bool operator<(const Infraccion&);
    double operator++(void);

};
ofstream& operator<<(ofstream&, Infraccion&);
void operator>>(ifstream&, Infraccion&);

#endif /* INFRACCION_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 07:28 PM
 */

#include <fstream>

using namespace std;

#ifndef INFRACCION_H
#define INFRACCION_H

class Infraccion {
public:
    Infraccion();
    virtual ~Infraccion();
    
    int getCodigo();
    double getMonto();
    char* getConcepto();
    char* getGravedad();
    
    void setConcepto(char* entrada);
    void setCodigo(int entrada);
    void setMonto(int entrada);
    void setGravedad(char* entrada);
    
    
    bool operator<(Infraccion b);
    bool operator>(Infraccion b);
    bool operator==(Infraccion b);
    
    void imprimir(ofstream &out);
    void leer(ifstream &in);
    
private:
    int codigo;
    double monto;
    char *concepto;
    char *gravedad;
};

#endif /* INFRACCION_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   libro.h
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:02 AM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;

class libro {
public:
    libro();
    virtual ~libro();
    /*Metodos selectores*/
    void SetMonto(double monto);
    double GetMonto() const;
    void SetNVend(int nVend);
    int GetNVend() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAutor(const char* autor);
    void GetAutor(char *) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char *) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    
    /*Metodos extra de lectura y escritura*/
    void leerDatos(ifstream&);
    void imprimir(ofstream&);
    
    /*Sobrecarga de operadores*/
    void operator ++(int);
    friend ifstream& operator >>(ifstream &, libro &);
    friend ofstream& operator <<(ofstream &, libro &);
    bool operator <(const libro &);
    void operator =(const libro &);
    
private:
    char *codigo;
    char *titulo;
    char *autor;
    double precio;
    int nVend;
    double monto;
};

#endif /* LIBRO_H */


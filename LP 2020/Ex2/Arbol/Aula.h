/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aula.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:52 AM
 */

#ifndef AULA_H
#define AULA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Aula {
private:
    char *clave,*nombre,*tipo;
    int capacidad,codigo,numero;
public:
    Aula();
    Aula(const Aula& orig);
    virtual ~Aula();
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetCapacidad(int capacidad);
    int GetCapacidad() const;
    void SetTipo(const char*  );
    void GetTipo(char*) const;
    void SetNombre(const char*  );
    void GetNombre(char*) const;
    void SetClave(const char*  );
    void GetClave(char*) const;
    
    void leer(ifstream&);
    void imprimir(ofstream&);
    
    void operator=(const Aula&);
    bool operator==(const Aula&);
    bool operator>(const Aula&);
    bool operator<(const Aula&);
    void SetNumero(int numero);
    int GetNumero() const;
    
};
ofstream& operator<<(ofstream&, Aula&);
void operator>>(ifstream&, Aula&);

#endif /* AULA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.h
 * Author: crimson
 *
 * Created on July 15, 2020, 4:49 PM
 */

#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class Profesor {
private:
    int cod;
    char *nom,*categoria,*dedicacion;
public:
    Profesor();
    Profesor(const Profesor& orig);
    virtual ~Profesor();
    void SetDedicacion(const char*  );
    void GetDedicacion(char*) const;
    void SetCategoria(const char*  );
    void GetCategoria(char*) const;
    void SetNom(const char*  );
    void GetNom(char*) const;
    void SetCod(int cod);
    int GetCod() const;

    void operator=(const Profesor& );
};

ofstream& operator<<(ofstream&, Profesor&);
void operator>>(ifstream&, Profesor&);
#endif /* PROFESOR_H */


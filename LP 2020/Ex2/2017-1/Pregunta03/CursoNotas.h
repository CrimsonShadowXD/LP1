/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursoNotas.h
 * Author: crimson
 *
 * Created on July 19, 2020, 7:03 PM
 */

#ifndef CURSONOTAS_H
#define CURSONOTAS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class CursoNotas {
private:
    char *codigo;
    int nota;
public:
    CursoNotas();
    CursoNotas(const CursoNotas& orig);
    virtual ~CursoNotas();
    void SetNota(int nota);
    int GetNota() const;
    void SetCodigo(const char*  );
    void GetCodigo(char*) const;
    
    void operator=(const CursoNotas& );
    bool operator==(const CursoNotas&);
    bool operator>(const CursoNotas&);
    bool operator<(const CursoNotas&);

};
ofstream& operator<<(ofstream&, CursoNotas&);
void operator>>(ifstream&, CursoNotas&);   

#endif /* CURSONOTAS_H */


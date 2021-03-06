/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaBanco.h
 * Author: crimson
 *
 * Created on July 15, 2020, 5:38 PM
 */

#ifndef LISTABANCO_H
#define LISTABANCO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class ListaBanco {
private:
    char *nom,tipo;
    int cod;
public:
    ListaBanco();
    ListaBanco(const ListaBanco& orig);
    virtual ~ListaBanco();
    void SetCod(int cod);
    int GetCod() const;
    void SetNom(const char*);
    void GetNom(char*) const;

    void operator=(const ListaBanco& );
    void SetTipo(char tipo);
    char GetTipo() const;
};
ofstream& operator<<(ofstream&, ListaBanco&);
void operator>>(ifstream&, ListaBanco&);

#endif /* LISTABANCO_H */


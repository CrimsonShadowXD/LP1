/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasePallet.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 09:21 AM
 */
#include <fstream>
using namespace std;
#ifndef BASEPALLET_H
#define BASEPALLET_H

class BasePallet {
public:
    BasePallet();
    virtual ~BasePallet();
    
    void SetId(char* ide);
    void GetId(char *ide) const;
    
    virtual void leerDatos(ifstream&)=0;
    virtual void imprimirDatos(ofstream&)=0;
    virtual char devolverTipo()=0;
     
private:
    char* id;
};

#endif /* BASEPALLET_H */


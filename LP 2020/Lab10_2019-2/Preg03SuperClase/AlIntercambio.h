
/* 
 * File:   AlIntercambio.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 6 de julio de 2020, 18:24
 */
#include <fstream>
#include "BaseAlum.h"

using namespace std;

#ifndef ALINTERCAMBIO_H
#define ALINTERCAMBIO_H

class AlIntercambio: public BaseAlum {
private:
    char *pais;
    char **idiomas;
    int nSemestres;
    

public:
    AlIntercambio();
    virtual ~AlIntercambio();
    
    void setNSemestres(int nSemestres);
    int getNSemestres() const;
    void setIdiomas(char** &idiomas);
    void setPais(char* pais);
    char* getPais() const;
    
       void imprimir(ofstream &out);
       void leer(ifstream &in);
       char getTipo();

};

#endif /* ALINTERCAMBIO_H */


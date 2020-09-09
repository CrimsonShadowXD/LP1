

/* 
 * File:   Intercambio.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 09:37 PM
 */

#include <fstream>
#include "Alumno.h"

using namespace std;

#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

class Intercambio: public Alumno {
public:
    Intercambio();
    virtual ~Intercambio();
    
    void setPais(char *entrada);
    void setIdioma(char* entrada);
    void setSemestres(int entrada);
    
    char* getPais();
    char* getIdioma();
    int getSemestres();
    
    char getTipo();
    
    void imprimir(ofstream &out);
    void leer(ifstream &in);
    
private:
    char *pais;
    char *idioma;
    int semestres;
};

#endif /* INTERCAMBIO_H */



/* 
 * File:   CursoNota.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 10:17 PM
 */
#include <fstream>

using namespace std;

#ifndef CURSONOTA_H
#define CURSONOTA_H

class CursoNota {
public:
    CursoNota();
    virtual ~CursoNota();
    
    void setCodigo(char *entrada);
    void setNota(int entrada);
    
    char* getCodigo();
    int getNota();
    
    void imprimir(ofstream &out);
    void leer(ifstream &in);
    
private:
    char *codigo;
    int nota;
};

ofstream& operator<<(ofstream &out, CursoNota &reg);

#endif /* CURSONOTA_H */


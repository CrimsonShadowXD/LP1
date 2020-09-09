
/* 
 * File:   ListaNotas.h
 * Author: Rodrigo Agama
 *
 * Created on 5 de julio de 2020, 14:46
 */
#include "Nota.h"
#include "NodoNota.h"
#include <fstream>

using namespace std;

#ifndef LISTANOTAS_H
#define LISTANOTAS_H

class ListaNotas {
private:
    NodoNota *lista;
public:
    ListaNotas();
    virtual ~ListaNotas();
    
    void agregarNota(Nota &entrada);
    void imprimirLista(ofstream &in);

};

#endif /* LISTANOTAS_H */

